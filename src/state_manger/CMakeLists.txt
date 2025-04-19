cmake_minimum_required(VERSION 3.8)
project(state_manger)

# Default to C++17
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core highgui imgcodecs imgproc videoio)
find_package(asdfr_msgs REQUIRED)
find_package(xrf2_msgs REQUIRED)


 
add_library(${PROJECT_NAME} SHARED
    src/state_manger.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${OpenCV_INCLUDE_DIRS}
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include/${PROJECT_NAME}>"
)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  rclcpp_components
  sensor_msgs
  geometry_msgs
  std_msgs
  cv_bridge
  asdfr_msgs
  xrf2_msgs
)
target_link_libraries(${PROJECT_NAME}
  ${OpenCV_LIBS}
)

rclcpp_components_register_node(${PROJECT_NAME} PLUGIN "state_manger::StateManger" EXECUTABLE state_manger_exec)


install(
  TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include)

install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})

ament_export_libraries(${PROJECT_NAME})

ament_export_targets(${PROJECT_NAME})
ament_export_dependencies(rclcpp_components cv_bridge)
ament_package()
