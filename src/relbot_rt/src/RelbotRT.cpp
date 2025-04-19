#include "RelbotRT.hpp"
 /*
            State           Value
            Idle            1
            Initialising    2
            Initialised     3 // when initailized, start running.
            Run             4
            Stopping        5
            Stopped         6
            Pausing         7
            Paused          8
            Error           9
            Quit            10

        */

RelbotRT::RelbotRT(uint write_decimator_freq, uint monitor_freq) :
XenoFrt20Sim(write_decimator_freq, monitor_freq, file, &data_to_be_logged),
    file(1,"/temp/relbotrt","bin"),
    left_encoder(),
    right_encoder() 
{
    printf("%s: Constructing rampio\n", __FUNCTION__);
    if(!logger.isInitialised()){
        logger.initialise();
    }
    controller = new LoopController();
    controller->SetFinishTime(0.0);
    xeno_data.state = 1;
}

RelbotRT::~RelbotRT()
{
    delete controller;
}

int RelbotRT::initialising()
{
    evl_printf("initialising\n");
    ico_io.init();
    xeno_data.state = 2;
    return 1;
}

int RelbotRT::initialised()
{
    monitor.printf("initialised\n");
    xeno_data.state = 3;
    return 1;
}

int RelbotRT::run()
{
    xeno_data.state = 4;
    if(!logger.isStarted())
        logger.start();                             
    float v_ = ros_data.v;
    float w_ = ros_data.w;
    monitor.printf("Data: V:%.3f, w:%.3f\n", v, w);

    // ros outputs a twist v, w. This needs to be converted to v left and right.
    double s_ = RelbotRT::calculate_velocity_steering(w_);
    double d_ = RelbotRT::calculate_velocity_drive(v_);
    double set_v_left = RelbotRT::calculate_motor_velocity_left(d_, s_);
    double set_v_right = RelbotRT::calculate_motor_velocity_right(d_, s_);

    updateSoftEncoders(); // accounts for the opposite direction of both wheels.
    double left_position = left_encoder.get_angle_radians();
    double right_position = right_encoder.get_angle_radians();

    inputs[0] = left_position;
    inputs[1] = right_position;
    inputs[2] = set_v_left;
    inputs[3] = set_v_right;

    controller->Calculate(inputs, outputs);
    actuate_data.pwm1 = 2047 * (outputs[0]);    // positive = going back.
    actuate_data.pwm2 = 2047 * (outputs[1]);     // positive = going forward.
    return 0;
}

int RelbotRT::stopping()
{
    xeno_data.state = 5;
    evl_printf("stopping\n");
    logger.stop();
    RelbotRT::stop_motors();
    return 1;
}

int RelbotRT::stopped()
{
    xeno_data.state = 6;
    monitor.printf("stopped\n");
    return 0;
}

int RelbotRT::pausing()
{
    xeno_data.state = 7;
    evl_printf("pausing\n");
    RelbotRT::stop_motors();
    return 1 ;
}

int RelbotRT::paused()
{
    xeno_data.state = 8;
    monitor.printf("paused\n");
    return 0;
}

int RelbotRT::error()
{
    xeno_data.state = 9;
    monitor.printf("error\n");
    RelbotRT::stop_motors();
    return 0;
}

void RelbotRT::updateSoftEncoders() {
    // Update the left and right encoders using the data from the channels
    // the soft encoder class accounts for the non-zero initial encoder value by subtracting the inital value from all the samples.
    left_encoder.update_from_hard_encoder(sample_data.channel1);
    right_encoder.update_from_hard_encoder(16383 - sample_data.channel2); // unify the direction of both wheels.
}

double RelbotRT::calculate_velocity_steering( double angular_v){
    // angular velocity multiplied by distance between 2 wheels, divided by 2* the wheel radius or just the wheel diameter in meter.
    // the distance is roughly less than 2 wheels. I used pixels on the wheel diameter to estimate on 2 seperate images.
    return ((angular_v * 0.174) / (2 * 0.101));
}

double RelbotRT::calculate_velocity_drive(double linear_v){
    // The linear velocity in meter per sec divided by the wheel radius in meters.
    return (linear_v / 0.0505);
}

double RelbotRT::calculate_motor_velocity_left(double drive, double steering) {
    // retuns setpoints left
    return drive - steering;
}

double RelbotRT::calculate_motor_velocity_right(double drive, double steering) {
    // returns set points right
    return drive + steering;
}

void RelbotRT::stop_motors(){
    inputs[0] = 0;
    inputs[1] = 0;
    inputs[2] = 0;
    inputs[3] = 0;
    // manually set everything to 0, bypassing the controller in case of an error.
    actuate_data.pwm1 = 0; // positive = going back.
    actuate_data.pwm2 = 0; // positive = going forward.
}