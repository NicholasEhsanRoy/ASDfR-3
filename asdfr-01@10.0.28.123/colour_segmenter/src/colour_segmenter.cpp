#include "../include/colour_segmenter.hpp"

namespace colour_segmenter
{

  ColourSegmenter::ColourSegmenter(const rclcpp::NodeOptions &options)
      : Node("colour_segmenter", options)
  {
    parse_parameters();
    initialize();
  }

  void ColourSegmenter::initialize()
  {
    // Configure QoS
    auto filter_qos = rclcpp::QoS(depth_);
    (reliability_ == "best_effort") ? filter_qos.best_effort() : filter_qos.reliable();
    (durability_ == "transient_local") ? filter_qos.transient_local() : filter_qos.durability_volatile();
    (history_ == "keep_all") ? filter_qos.keep_all() : filter_qos.keep_last(depth_);

    pub_filter_ = this->create_publisher<sensor_msgs::msg::Image>("bw_image", filter_qos);

    auto filter_callback = [this](sensor_msgs::msg::Image::ConstSharedPtr msg) -> void
    {
      cv_bridge::CvImagePtr cv_ptr;
      cv::Mat hsv_image, color_mask;

      try
      {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        cv::cvtColor(cv_ptr->image, hsv_image, cv::COLOR_BGR2HSV);

        cv::Scalar lower_bound(lower_hue_, lower_saturation_, lower_value_);
        cv::Scalar upper_bound(upper_hue_, upper_saturation_, upper_value_);
        cv::inRange(hsv_image, lower_bound, upper_bound, color_mask);
        // Find contours in the binary mask
        std::vector<std::vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierarchy;
        cv::findContours(color_mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // Initialize variables for best circular object
        double bestCircularity = 0.0;
        int bestContourIndex = -1;

        // Loop through all contours
        for (size_t i = 0; i < contours.size(); i++) {
            double area = cv::contourArea(contours[i]);

            // Ignore very small contours (noise)
            if (area < 200) continue;

            // Fit a minimum enclosing circle
            cv::Point2f center;
            float radius;
            cv::minEnclosingCircle(contours[i], center, radius);
            double circleArea = CV_PI * radius * radius;

            // Compute circularity: Actual Area / Enclosing Circle Area
            double circularity = area / circleArea;

            // Update best circular object if circularity is highest
            if (circularity > bestCircularity && circularity > 0.5) {
                bestCircularity = circularity;
                bestContourIndex = i;
            }
        }

        // Create a mask for the best circular object
        cv::Mat circularObjectMask = cv::Mat::zeros(color_mask.size(), CV_8UC1);

        if (bestContourIndex != -1) {
            // Draw the best circular object
            cv::drawContours(circularObjectMask, contours, bestContourIndex, cv::Scalar(255), cv::FILLED);
        }

        // Apply the mask to keep only the best circular object
        cv::Mat result;
        cv::bitwise_and(color_mask, circularObjectMask, result);

        cv_bridge::CvImage color_mask_msg;
        color_mask_msg.header = msg->header;
        color_mask_msg.encoding = sensor_msgs::image_encodings::MONO8;
        color_mask_msg.image = result;
        pub_filter_->publish(*color_mask_msg.toImageMsg());
      }
      catch (cv_bridge::Exception &e)
      {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
        return;
      }

      if (show_camera_)
      {
        cv::imshow(colour_name_ + " Mask", color_mask);
        cv::waitKey(1);
      }
    };

    sub_filter_ = create_subscription<sensor_msgs::msg::Image>(image_source_topic_, filter_qos, filter_callback);
  }

  void ColourSegmenter::parse_parameters()
  {
    colour_name_ = this->declare_parameter("colour_name", "Green");
    brightness_threshold_ = this->declare_parameter("brightness_threshold", 50);
    image_source_topic_ = this->declare_parameter("image_source_topic", "image");

    lower_hue_ = this->declare_parameter("lower_hue", 27);
    upper_hue_ = this->declare_parameter("upper_hue", 85);
    lower_saturation_ = this->declare_parameter("lower_saturation", brightness_threshold_);
    upper_saturation_ = this->declare_parameter("upper_saturation", 255);
    lower_value_ = this->declare_parameter("lower_value", brightness_threshold_);
    upper_value_ = this->declare_parameter("upper_value", 255);
    reliability_ = this->declare_parameter("reliability", "reliable");
    durability_ = this->declare_parameter("durability", "volatile");
    history_ = this->declare_parameter("history", "keep_last");
    depth_ = this->declare_parameter("depth", 10);
    show_camera_ = this->declare_parameter("show_camera", true);
  }

} // namespace colour_segmenter

RCLCPP_COMPONENTS_REGISTER_NODE(colour_segmenter::ColourSegmenter)
