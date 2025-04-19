Package state_manager
-----------------------------------------------
Description:Responsible for switching the real-time controller to running mode from the initialized mode.

Input:
/Xeno2Ros 
        Type: XRF2_msgs/msg/Xeno2Ros
        Current state value.
Output:
/Command 
        Type: std_msgs/msg/Int32
        state transition command
Run:
        In a terminal run the following commands:
        ros2 run state_manger state_manger_exec

Parameters:
        bool test_mode: if true, the node runs a sequence of set positions for 25 seconds, if false, the node requires coordinates to send set positions to relbot

Note:
    Make sure to run RELBOT in twist mode.
