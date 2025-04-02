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

    void ObjectIdentifier::initialize() {
        auto qos = rclcpp::QoS(depth_);
        history_ == "keep_all" ? qos.keep_all() : qos.keep_last(depth_);

        pub_ = this->create_publisher<sensor_msgs::msg::Image>("object_position", qos);
        frame_size_publisher_ = this->create_publisher<geometry_msgs::msg::Vector3>("frame_size", 10);
        frame_width_ = 0;
        frame_height_ = 0;
        auto image_callback = [this](sensor_msgs::msg::Image::ConstSharedPtr msg) -> void {
            cv_bridge::CvImagePtr cv_ptr;
            try {
                cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::MONO8);
            } catch (cv_bridge::Exception &e) {
                RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
                return;
            }

            frame_width_ = cv_ptr->image.cols;
            frame_height_ =  cv_ptr->image.rows;

            std::tuple<int, int> location = this->find_center_of_gravity(cv_ptr->image);
            cv::Mat padded_image = this->padImage(cv_ptr->image, 320, location);


            RCLCPP_INFO(this->get_logger(), "Publishing image_location x = %.2f \t y = %.2f", static_cast<double>(std::get<0>(location)), static_cast<double>(std::get<1>(location)));
            cv_bridge::CvImage color_mask_msg;
            color_mask_msg.header = msg->header;
            color_mask_msg.encoding = sensor_msgs::image_encodings::MONO8;
            color_mask_msg.image = padded_image;
            pub_->publish(*color_mask_msg.toImageMsg());

            cv::Mat color_image; // to see the dran on circle
            cv::cvtColor(cv_ptr->image, color_image, cv::COLOR_GRAY2BGR);
            cv::circle(color_image, cv::Point(std::get<0>(location) , std::get<1>(location)), 5, cv::Scalar(0, 255, 0), -1);
            cv::imshow("Detected Object on /bw_image", color_image);
            cv::waitKey(1);
        };
        sub_ = create_subscription<sensor_msgs::msg::Image>("bw_image", qos, image_callback);

    }

    void ObjectIdentifier::publish_frame_size() {
        geometry_msgs::msg::Vector3 frame_size_msg;
        frame_size_msg.x = frame_width_;
        frame_size_msg.y = frame_height_;
        frame_size_msg.z = 0.0;
        frame_size_publisher_->publish(frame_size_msg);
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
