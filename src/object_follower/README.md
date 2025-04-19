Package object_follower
-----------------------------------------------
Description:This package recieves coordinates and radius of an identified object, and publishes twist to the real-time thread to follow the object.

Input:
/object_position 
        Type: asdfr_msgs/msg/IdentifiedObject
        Object to follow
Output:
/Ros2Xeno 
        Type: XRF2_msgs/msg/Ros2Xeno
        v,w values to be sent to the real time loop
Run:
        In a terminal run the following commands:
        ros2 run object_follower object_follower_exec --ros-args --params-file src/object_follower/config/object_follower.yml

Parameters:
        float linear_scalef: the linear twist speed is proportional to the scale factor multiplied by error
        float angular_scalef: the angular twist speed is proportional to the scale factor multiplied by error
        float follower_threshold: The vertical threshold where the robot stops following if the object is above.

