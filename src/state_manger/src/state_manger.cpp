#include "../include/state_manger.hpp"

namespace state_manger {
    StateManger::StateManger(const rclcpp::NodeOptions &options)
        : Node("state_manger", options) {
        parse_parameters();
        initialize();
    }
    void StateManger::state_change_callback(const xrf2_msgs::msg::Xeno2Ros::SharedPtr msg){
        /*
            State           Value
            Idle            1
            Initialising    2
            Initialised     3 // when initailized, start running.
            Run             4
            Stopping        5
            Stopped         6
            Pausing         7
            Paused          8
            Error           9
            Quit            10

        */
       // This node could be used to control the relbot manually by a user, but right now, only the initialized state is handled.
        if(msg->satate == 3){
            std_msgs::msg::Int32 command_msg;
            command_msg.data= 1;
            pub_->publish(command_msg);
        }
    }

    void StateManger::initialize() {
        // creates a subscriber to xeno.
        sub_ = this->create_subscription<xrf2_msgs::msg::Xeno2Ros>("/Xeno2Ros", 1, std::bind(&StateManger::state_change_callback, this, _1));     
        // create command publisher
        pub_ = this->create_publisher<std_msgs::msg::Int32>("Command", rclcpp::QoS(10));

    }
    void StateManger::parse_parameters() {

    }
}

RCLCPP_COMPONENTS_REGISTER_NODE(state_manger::StateManger)
