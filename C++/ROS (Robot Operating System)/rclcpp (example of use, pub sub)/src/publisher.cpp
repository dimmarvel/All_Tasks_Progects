#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher(std::string topic)
    : Node("some_publisher"), _count(0)
    {
        _publisher = this->create_publisher<std_msgs::msg::String>(topic.c_str(), 10);
        _timer = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }
private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();

        std::cout << "Input message(" << 5 - _count << "): ";
        std::cin.clear();
        std::cin.ignore();
        std::getline(std::cin,message.data);

        RCLCPP_INFO(this->get_logger(), "Publisher: '%s' ", message.data.c_str());

        _publisher->publish(message);

        if(++_count > 5)
            if(rclcpp::shutdown())
                RCLCPP_FATAL(this->get_logger(), "Work end correctly, _count = '%d'", _count);
    }
private:
    rclcpp::TimerBase::SharedPtr _timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _publisher;
    uint16_t _count;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    std::string topic;
    std::cout << "Input topic: ";
    std::cin >> topic;

    rclcpp::spin(std::make_shared<MinimalPublisher>(topic));
    return 0;
}