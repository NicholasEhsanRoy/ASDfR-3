#include "../include/object_follower.hpp"

namespace object_follower {
    ObjectFollower::ObjectFollower(const rclcpp::NodeOptions &options)
        : Node("object_follower", options) {
        parse_parameters();
        initialize();
    }

    void ObjectFollower::publish_twist_message(double v, double w) {
        xrf2_msgs::msg::Ros2Xeno twist_msg;
        twist_msg.v = v;
        twist_msg.w = w;
        pub_->publish(twist_msg);
    }

    void ObjectFollower::object_callback(const asdfr_msgs::msg::IdentifiedObject::SharedPtr msg) {
        if (msg->x == -1 || msg->y == -1 || msg->r == -1) {
            publish_twist_message(0, 0);
            return;
        }
        destination_error[0] = (desired_destination[0] - static_cast<float>(msg->x)); // eu
        destination_error[1] = (desired_destination[1] - static_cast<float>(msg->y)); 
        destination_error[2] = (desired_destination[2] - static_cast<float>(msg->r)); // er
        if(destination_error[2]  > 0){
            v_ = linear_sf_*destination_error[2]*(1-(fabs(destination_error[1])/follower_thr_));
        }else{
            v_ = linear_sf_*destination_error[2];
        }
        w_ = angular_sf_*destination_error[0];
        RCLCPP_INFO(this->get_logger(), "Twist = %.2f \t z = %.2f", v_, w_);
        publish_twist_message(v_, w_);
    }
    
    void ObjectFollower::initialize() {
        desired_destination.assign({125.0, 125.0, 75.0});
        destination_error.assign({0.0, 0.0, 0});
        pub_ = this->create_publisher<xrf2_msgs::msg::Ros2Xeno>("/Ros2Xeno", rclcpp::QoS(10));
        sub_ = create_subscription<asdfr_msgs::msg::IdentifiedObject>("object_position", 10,
            std::bind(&ObjectFollower::object_callback, this, std::placeholders::_1));
    }
    
    void ObjectFollower::parse_parameters() {
        linear_sf_ = this->declare_parameter("linear_scalef", 0.1);
        angular_sf_ = this->declare_parameter("angular_scalef", 0.01);
        follower_thr_ = this->declare_parameter("follower_threshold", 50.0);
    }


}

RCLCPP_COMPONENTS_REGISTER_NODE(object_follower::ObjectFollower)
