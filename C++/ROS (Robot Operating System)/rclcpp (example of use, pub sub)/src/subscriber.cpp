#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
    MinimalSubscriber()
    : Node("some_subscriber")
    {
        _subscription = this->create_subscription<std_msgs::msg::String>(
                "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    };

private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(),"I heard: '%s'", msg->data.c_str());
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscription;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc,argv);

    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    return 0;
}