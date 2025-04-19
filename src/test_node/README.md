Package test_node
-----------------------------------------------
Description:This package sends a seriese of twist setpoints that follow a straight line and then a 90 degree angle, once every 33 millisec.

Input:

Output:
/Ros2Xeno 
        Type: XRF2_msgs/msg/Ros2Xeno
        v, w twist velocity
Run:
        In a terminal run the following commands:
        ros2 run test_node test_node_exec --ros-args --params-file src/test_node/config/test_node.yml

Parameters:
        float linear_velocity: The velocity during the straight line portion of the test

Note:
    Make sure to run RELBOT in twist mode.
