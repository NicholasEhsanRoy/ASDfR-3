#ifndef STATE_MANGER_HPP
#define STATE_MANGER_HPP

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
#include "xrf2_msgs/msg/xeno2_ros.hpp"
#include <std_msgs/msg/int32.hpp>

namespace state_manger {
    class StateManger : public rclcpp::Node {
        public:
            explicit StateManger(const rclcpp::NodeOptions &options);
        private:
        void parse_parameters();
        void initialize();

        void state_change_callback(const xrf2_msgs::msg::Xeno2Ros::SharedPtr msg);
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_;  
        rclcpp::Publisher<xrf2_msgs::msg::Xeno2Ros>::SharedPtr sub_;  

    };
} 

#endif