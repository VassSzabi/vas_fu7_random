#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <string>
#include <cstdlib>

using namespace std::chrono_literals;

class VasFu7Node : public rclcpp::Node {
public:
  VasFu7Node() : Node("vas_fu7_node"), temp_(22.5) {
    // Beszédes topicnév: sensor_temperature
    publisher_ = this->create_publisher<std_msgs::msg::String>("sensor_temperature", 10);
    timer_ = this->create_wall_timer(1000ms, std::bind(&VasFu7Node::timer_callback, this));
  }
private:
  void timer_callback() {
    auto message = std_msgs::msg::String();
    // Érdemi funkció: folyamatosan változó hőmérséklet szimulálása
    temp_ += ((std::rand() % 10) - 4) / 10.0; 
    message.data = "Jelentes: A gepterem homerseklete: " + std::to_string(temp_).substr(0, 4) + " C";
    
    RCLCPP_INFO(this->get_logger(), "Publikalva: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  double temp_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VasFu7Node>());
  rclcpp::shutdown();
  return 0;
}
