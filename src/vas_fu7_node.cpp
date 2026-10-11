#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class VasFu7Node : public rclcpp::Node {
public:
  VasFu7Node() : Node("vas_fu7_node") {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(1000ms, std::bind(&VasFu7Node::timer_callback, this));
  }
private:
  void timer_callback() {
    auto message = std_msgs::msg::String();
    message.data = "Hello a vas_fu7_node-bol!";
    RCLCPP_INFO(this->get_logger(), "Publikalva: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VasFu7Node>());
  rclcpp::shutdown();
  return 0;
}
