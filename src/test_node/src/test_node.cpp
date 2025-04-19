#include "../include/test_node.hpp"

namespace test_node {
    TestNode::TestNode(const rclcpp::NodeOptions &options)
        : Node("test_node", options) {
        parse_parameters();
        initialize();
    }

    void TestNode::generate_velocity_sequence() { // generate  a test sequence for the relbot.
        const double linear_vel = linear_v_;    // m/s
        const double angular_vel = 0.5;   // rad/s
        const int rate = 30;              // Hz
        const int move_steps = 60;        // 2 sec
        const int stop_steps = 15;        // 0.5 sec
        const int turn_steps = static_cast<int>((M_PI / 2) / angular_vel * rate);  // ~47 steps
        v_seq_.fill(0.0);
        w_seq_.fill(0.0);
        int i = 0;
        // Move forward
        for (; i < move_steps; ++i) {
            v_seq_[i] = linear_vel;
        }
        // i is now 60
        // Stop from 60 to 15
        for (int j = 0; j < stop_steps; ++j, ++i) {
            // already filled with 0s
        }
        // i is now 75
        // Turn 90 degrees now 
        for (int j = 0; j < turn_steps; ++j, ++i) {
            w_seq_[i] = angular_vel;
        }
        // i id no longer needed.
        // Final stop (rest of array remains 0)
    }

    void TestNode::publish_twist_message(double v, double w) {
        xrf2_msgs::msg::Ros2Xeno twist_msg;
        twist_msg.v = v;
        twist_msg.w = w;
        pub_->publish(twist_msg);
    }

    void TestNode::timer_callback() {
        // as long as we are still below the max steps, keep sending from buffer.
        if (step_ < 200) {
            publish_twist_message(v_seq_[step_], w_seq_[step_]);
            step_++;
        } else {
            // not really needed, but why not.
            publish_twist_message(0.0, 0.0);  // hold position
        }
    }

    void TestNode::initialize() {
        // creates a publisher to xeno.
        pub_ = this->create_publisher<xrf2_msgs::msg::Ros2Xeno>("/Ros2Xeno", rclcpp::QoS(1000));
        // prep the data for testing.
        generate_velocity_sequence();
        // create a timer that follows 33 milliseconds to simulate the assumed setpoint flow from a camera.
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(33),
            std::bind(&TestNode::timer_callback, this)
        );
    }
    void TestNode::parse_parameters() {
        // this parameter influences the speed of going forward.
        linear_v_ = this->declare_parameter("linear_velocity", 0.1);

    }
}

RCLCPP_COMPONENTS_REGISTER_NODE(test_node::TestNode)
