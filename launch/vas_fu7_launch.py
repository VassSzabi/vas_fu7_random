from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='vas_fu7_random',
            executable='vas_fu7_node',
            name='vas_fu7_node',
            output='screen'
        )
    ])
