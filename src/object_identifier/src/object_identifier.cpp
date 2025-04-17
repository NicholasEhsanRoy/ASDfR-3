#include "../include/object_identifier.hpp"

namespace object_identifier {
    ObjectIdentifier::ObjectIdentifier(const rclcpp::NodeOptions &options)
        : Node("object_identifier", options) {
        parse_parameters();
        initialize();
    }

    cv::Mat ObjectIdentifier::padImage(cv::Mat &inputImage, int targetSize, std::tuple<int, int> location) {
        cv::Mat outputImage;

        // Check condition to determine if the output should be fully black
        if (std::get<0>(location) == -1 || std::get<1>(location) == -1) {
            outputImage = cv::Mat::zeros(targetSize, targetSize, inputImage.type());  // Fully black image
        } else {
            // Compute padding amounts
            int top = (targetSize - inputImage.rows) / 2;
            int bottom = targetSize - inputImage.rows - top;
            int left = (targetSize - inputImage.cols) / 2;
            int right = targetSize - inputImage.cols - left;

            // Pad the image with black pixels
            copyMakeBorder(inputImage, outputImage, top, bottom, left, right, cv::BORDER_CONSTANT, cv::Scalar(0));
        }

        return outputImage;
    }
    
    double ObjectIdentifier :: calculate_radius(const cv::Mat &binary_image, const std::tuple<int, int> &center) {
        int x_center = std::get<0>(center);
        int y_center = std::get<1>(center);

        if (x_center == -1 || y_center == -1) {
            return -1.0; // Invalid center
        }

        double max_distance = 0.0;

        for (int y = 0; y < binary_image.rows; ++y) {
            for (int x = 0; x < binary_image.cols; ++x) {
                if (binary_image.at<uchar>(y, x) > 0) {
                    double dist = std::hypot(x - x_center, y - y_center);
                    if (dist > max_distance) {
                        max_distance = dist;
                    }
                }
            }
        }

        return max_distance;
    }


    void ObjectIdentifier::initialize() {
        auto qos = rclcpp::QoS(depth_);
        if (history_ == "keep_all") {
            qos.keep_all();
        } else {
            qos.keep_last(depth_);
        }


        pub_ = this->create_publisher<asdfr_msgs::msg::IdentifiedObject>("object_position", qos);
        auto image_callback = [this](sensor_msgs::msg::Image::ConstSharedPtr msg) -> void {
            cv_bridge::CvImagePtr cv_ptr;
            try {
                cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);
            } catch (cv_bridge::Exception &e) {
                RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
                return;
            }

            std::tuple<int, int> location = this->find_center_of_gravity(cv_ptr->image);
            int x_center = std::get<0>(location);
            int y_center = std::get<1>(location);
            double radius = calculate_radius(cv_ptr->image, location);
            RCLCPP_INFO(this->get_logger(), "found center x = %.2f \t y = %.2f \t r = %.2f", static_cast<double>(std::get<0>(location)), static_cast<double>(std::get<1>(location)), radius);
            auto message = asdfr_msgs::msg::IdentifiedObject();
            message.x = x_center;     
            message.y = y_center;     
            message.r = radius;

            pub_->publish(message);
            cv::Mat color_image;
            cv::cvtColor(cv_ptr->image, color_image, cv::COLOR_GRAY2BGR);
            if (x_center != -1 && y_center != -1) {
                cv::circle(color_image, cv::Point(x_center, y_center), 5, cv::Scalar(0, 255, 0), -1);
                cv::circle(color_image, cv::Point(x_center, y_center), static_cast<int>(radius), cv::Scalar(0, 255, 0), 2);
            }
            cv::imshow("Detected Object on /bw_image", color_image);
            cv::waitKey(1);
        };
        sub_ = create_subscription<sensor_msgs::msg::Image>("bw_image", qos, image_callback);

    }

    void ObjectIdentifier::parse_parameters() {
        history_ = declare_parameter("history", "keep_last");
        depth_ = declare_parameter("depth", 1);
    }

    std::tuple<int, int> ObjectIdentifier::find_center_of_gravity(cv::Mat &image) {
        cv::Moments m = cv::moments(image, true);
        if (m.m00 != 0) {
            int cx = static_cast<int>(m.m10 / m.m00);
            int cy = static_cast<int>(m.m01 / m.m00);
            return std::make_tuple(cx, cy);
        }
        // Return an invalid position if no object is found.
        return std::make_tuple(-1, -1);
    }

}

RCLCPP_COMPONENTS_REGISTER_NODE(object_identifier::ObjectIdentifier)
