Package relbot_rt
-----------------------------------------------
Description: Realtime controller part. This package gets a twist and converts it to a pwm signal
Input:
/Ros2Xeno 
        Type: XRF2_msgs/msg/Ros2Xeno
        v and w velocities to control the robot.
Output:
/Xeno2Ros 
        Type: XRF2_msgs/msg/Xeno2Ros
        Current state of the robot.
Run:
        In a terminal run the following commands:
        sudo ./build/RelbotRT/relbot_rt

