#ifndef OBJECT_LOCATOR_HPP
#define OBJECT_LOCATOR_HPP
#include "rcl_interfaces/msg/parameter_descriptor.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "rclcpp/exceptions.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "sensor_msgs/image_encodings.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include <tuple>
#include <opencv2/opencv.hpp>
#if __has_include(<cv_bridge/cv_bridge.hpp>)
    #include <cv_bridge/cv_bridge.hpp>
#elif __has_include(<cv_bridge/cv_bridge.h>)
    #include <cv_bridge/cv_bridge.h>
#else
    #error "Required cv_bridge header file not found"
#endif
#include "asdfr_msgs/msg/identified_object.hpp"

namespace object_identifier {
    class ObjectIdentifier : public rclcpp::Node {
        public:
            explicit ObjectIdentifier(const rclcpp::NodeOptions &options);

        private:
        void parse_parameters();
        void initialize();
        std::tuple<int, int> find_center_of_gravity(cv::Mat &image);
        cv::Mat padImage(cv::Mat &inputImage, int targetSize, std::tuple<int, int> location);
        std::string history_;
        size_t depth_;
        double calculate_radius(const cv::Mat &binary_image, const std::tuple<int, int> &center);
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_;
        rclcpp::Publisher<asdfr_msgs::msg::IdentifiedObject>::SharedPtr pub_;
        void publish_frame_size();
        double frame_width_;
        double frame_height_;

    };
} 

#endif