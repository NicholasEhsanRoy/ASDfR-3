#ifndef RELBOT_RT_HPP
#define RELBOT_RT_HPP

#include "XenoFrt20Sim.hpp"
#include "LoopController.h"
#include <cmath>
#include "SoftEncoder.hpp"
#include "cstdlib"
#pragma pack (1)    //https://carlosvin.github.io/langs/en/posts/cpp-pragma-pack/#_performance_test
struct data_log_struct
{
    // Leave it blank for now, use this to log data
    int data = 0;

};
#pragma pack(0)

class RelbotRT : public XenoFrt20Sim
{
public:
    RelbotRT(uint write_decimator_freq, uint monitor_freq);
    ~RelbotRT();
private:
    XenoFileHandler file;
    LoopController * controller;

    double inputs[4];   // instead of u for readablity
    double outputs[2];  // instead of y
    void stop_motors(); // Stop motor in pause and stop cases.
    double calculate_velocity_steering(double angular_v); // twist to set point conversion helper function.
    double calculate_velocity_drive(double linear_v); // twist to set point conversion helper function
    double calculate_motor_velocity_left(double drive, double steering);
    double calculate_motor_velocity_right(double drive, double steering);
    void updateSoftEncoders(); // feed the encoder values to the soft encoder class
    SoftEncoder left_encoder; // encoder to angle calculators
    SoftEncoder right_encoder;
    struct data_log_struct data_to_be_logged;

protected:
    //Functions
    int initialising() override;
    int initialised() override;
    int run() override;
    int stopping() override;
    int stopped() override;
    int pausing() override;
    int paused() override;
    int error() override;
    // current error
    int current_error = 0;
};

#endif // RELBOTRT_HPP