cmake_minimum_required(VERSION 3.8)
project(asdfr_msgs)

# Add these lines to find required packages
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)  # <-- Add this line

# Generate messages and specify dependencies
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/IdentifiedObject.msg"
  DEPENDENCIES std_msgs  # <-- Add this line
)

# Export dependencies
ament_export_dependencies(rosidl_default_runtime)
ament_package()