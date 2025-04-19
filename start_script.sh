#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

echo "Sourcing ROS2 setup..."
source ./install/setup.bash

echo "Setting PID config path..."
export ASDFR_01_PID_CONFIG_PATH=~/pid_confg.csv

echo "Starting cam2image..."
ros2 run cam2image_vm2ros cam2image --ros-args --params-file src/cam2image_vm2ros/config/cam2image_relbot.yaml &



echo "Starting colour_segmenter..."
ros2 run colour_segmenter colour_segment --ros-args --params-file src/colour_segmenter/config/colour_segmenter.yml &



echo "Starting object_identifier..."
ros2 run object_identifier object_identifier_node --ros-args --params-file src/object_identifier/config/object_identifier.yml &



echo "Starting object_follower..."
ros2 run object_follower object_follower_exec --ros-args --params-file src/object_follower/config/object_follower.yml &



echo "Starting relbot_rt (requires sudo)..."
sudo ./build/RelbotRT/relbot_rt &



echo "Starting RosXenoBridge..."
ros2 run ros_xeno_bridge RosXenoBridge &



echo "Publishing start command to /Command..."
ros2 run state_manger state_manger_exec


echo "All processes started."
