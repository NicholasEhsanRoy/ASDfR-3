#include "../include/test_node.hpp"

namespace test_node {
    TestNode::TestNode(const rclcpp::NodeOptions &options)
        : Node("test_node", options) {
        parse_parameters();
        initialize();
    }
    void updateWeights(std::vector<std::vector<float>>& weights,
                   const std::vector<float>& error_vector,
                   const std::vector<float>& twist_vector,
                   float learning_rate)
    {
         for (int i = 0; i < 3; ++i) {
            weights[0][i] -= learning_rate * error_vector[i];
            // Update weights for angular velocity (omega)
            weights[1][i] -= learning_rate * error_vector[i];
        }
    }
    void TestNode::computeTwistVector(const std::vector<std::vector<float>>& weights,
                        const std::vector<float>& error_vector,
                        std::vector<float>& twist_vector)
    {
        twist_vector.assign(0, 0);
        twist_vector[0]= weights[0][0] * error_vector[0] + weights[0][1] * error_vector[1] + weights[0][2] * error_vector[2];
        twist_vector[1]= weights[1][0] * error_vector[0] + weights[1][1] * error_vector[1] + weights[1][2] * error_vector[2];
        twist_vector[0] = std::max(-1.0f, std::min(1.0f, twist_vector[0]));
        twist_vector[1] = std::max(-1.0f, std::min(1.0f, twist_vector[1]));
    }

    void TestNode::publish_twist_message(double x, double z) {
        geometry_msgs::msg::Twist twist_msg;
        twist_msg.linear.x = x;
        twist_msg.angular.z = z;
        pub_->publish(twist_msg);
    }

    void TestNode::object_callback(const asdfr_msgs::msg::IdentifiedObject::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "found center x = %.2f \t y = %.2f \t r = %.2f", static_cast<double>(msg->x), static_cast<double>(msg->y), msg->r);
        if (msg->x == -1 || msg->y == -1 || msg->r == -1) {
            twist_vector[0] = 0;
            twist_vector[1] = 0;
            publish_twist_message(twist_vector[0], twist_vector[1]);
            return;
        }
        destination_error[0] = (desired_destination[0] - static_cast<float>(msg->x)); // eu
        destination_error[1] = (desired_destination[1] - static_cast<float>(msg->y)); 
        destination_error[2] = (desired_destination[2] - static_cast<float>(msg->r)); // er
        double v = 0;
        double w = 0;
        double eu_thresh = 50;
        if(destination_error[2]  > 0){
            v = 0.1*destination_error[2]*(1-(fabs(destination_error[0])/eu_thresh));
        }else{
            v = 0.1*destination_error[2];
        }
        w = 0.01*destination_error[0];
        RCLCPP_INFO(this->get_logger(), "Twist = %.2f \t z = %.2f", v, w);
        publish_twist_message(v, w);
    }
    
    void TestNode::initialize() {
        desired_destination.assign({125.0, 125.0, 75.0});
        destination_error.assign({0.0, 0.0, 0});
        twist_vector.assign({0.0, 0.0});
        weights.assign({
            {0.1f, 0.1f, 0.1f},  
            {0.1f, 0.1f, 0.1f}
        });
        pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/input/twist", rclcpp::QoS(10));
        sub_ = create_subscription<asdfr_msgs::msg::IdentifiedObject>("object_position", 10,
            std::bind(&TestNode::object_callback, this, std::placeholders::_1));

    }
    void TestNode::parse_parameters() {
    }


}

RCLCPP_COMPONENTS_REGISTER_NODE(test_node::TestNode)
