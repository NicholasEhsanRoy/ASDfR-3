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
#include <chrono>

namespace test_node {
    class TestNode : public rclcpp::Node {
        public:
            explicit TestNode(const rclcpp::NodeOptions &options);
        private:
        void parse_parameters();
        void initialize();
        rclcpp::Publisher<xrf2_msgs::msg::Ros2Xeno>::SharedPtr pub_;  
        void publish_twist_message(double x, double z);
        rclcpp::TimerBase::SharedPtr timer_;
        void timer_callback();
        static constexpr size_t sequence_size = 200;  // Adjust as needed
        std::array<double, sequence_size> v_seq_;
        std::array<double, sequence_size> w_seq_;
        size_t step_ = 0;
        void generate_velocity_sequence();
        double linear_v_;
    };
} 

#endif