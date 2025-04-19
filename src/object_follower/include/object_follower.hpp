#ifndef TEST_NODE_HPP
#define TEST_NODE_HPP

#include "rcl_interfaces/msg/parameter_descriptor.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "rclcpp/exceptions.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "sensor_msgs/image_encodings.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include <tuple>
#include "std_msgs/msg/int16_multi_array.hpp"      
#include <array> 
#include <cstdint>
#include <chrono>
#include <opencv2/opencv.hpp>
#if __has_include(<cv_bridge/cv_bridge.hpp>)
    #include <cv_bridge/cv_bridge.hpp>
#elif __has_include(<cv_bridge/cv_bridge.h>)
    #include <cv_bridge/cv_bridge.h>
#else
    #error "Required cv_bridge header file not found"
#endif
#include "asdfr_msgs/msg/identified_object.hpp"
#include "xrf2_msgs/msg/ros2_xeno.hpp"

#include <vector>
#include <iostream>
#include <array>
#include <cmath>

namespace object_follower {
    class ObjectFollower : public rclcpp::Node {
        public:
            explicit ObjectFollower(const rclcpp::NodeOptions &options);
        private:
        void parse_parameters();
        void initialize();
        rclcpp::Subscription<asdfr_msgs::msg::IdentifiedObject>::SharedPtr sub_;
        rclcpp::Publisher<xrf2_msgs::msg::Ros2Xeno>::SharedPtr pub_;  
        void publish_twist_message(double x, double z);
        void object_callback(const asdfr_msgs::msg::IdentifiedObject::SharedPtr msg) ;
        std::vector<float> desired_destination;
        std::vector<float> destination_error;
        double linear_sf_ ;
        double angular_sf_ ;
        double follower_thr_;
        double v_;
        double w_;
    };
} 

#endif