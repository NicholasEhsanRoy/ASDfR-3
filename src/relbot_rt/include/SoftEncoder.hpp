#pragma once

#include <cmath>

class SoftEncoder {
public:
    // Constants based on Python defaults
    static constexpr int HARD_ENCODER_MAX = 16383;
    static constexpr int COUNTS_PER_REVOLUTION = 63816; //
    static constexpr double MAX_SOFT_ENCODER_VALUE = 16383 * 3.895; // number of buffers in a full turn.
    static constexpr int INVALID_PREV_HARD = -99999999;

    // Constructor
    SoftEncoder()
        : hard_encoder_max(HARD_ENCODER_MAX),
          counts_per_revolution(COUNTS_PER_REVOLUTION),
          max_soft_encoder_value(MAX_SOFT_ENCODER_VALUE),
          wrap_count(0),
          prev_hard(INVALID_PREV_HARD),
          soft_encoder(0),
          direction(1),
          initial_offset_set(false),
          initial_offset(0) {}

    void update_from_hard_encoder(int new_hard) {
        if (!initial_offset_set) {
            initial_offset = new_hard;
            new_hard = 0;
            initial_offset_set = true;
        } else {
            new_hard -= initial_offset;
        }

        if (prev_hard == INVALID_PREV_HARD) {
            prev_hard = new_hard;
            return;
        }

        int diff = new_hard - prev_hard;
        int half_range = (hard_encoder_max + 1) / 2;

        if (diff > half_range) {
            diff -= (hard_encoder_max + 1);
            wrap_count -= 1;
            direction = -1;
        } else if (diff < -half_range) {
            diff += (hard_encoder_max + 1);
            wrap_count += 1;
            direction = 1;
        }

        soft_encoder += diff;
        // We used to wrap the encoder, but the 20sim model needs an accumulated angle
        // if (soft_encoder > max_soft_encoder_value) {
        //     soft_encoder = 0;
        // }

        // if (soft_encoder < 0) {
        //     soft_encoder = max_soft_encoder_value - 1;
        // }

        prev_hard = new_hard;
    }

    double get_angle_radians() const {
    /*
        This used to be the 0:2pi logic
        double whole_turns = static_cast<int>(soft_encoder / counts_per_revolution);
        double fractional_turn = (soft_encoder - whole_turns * counts_per_revolution) / counts_per_revolution;
        return fractional_turn * 2 * M_PI;
    */
    //output accumulated position
        return (soft_encoder/counts_per_revolution)* 2 * M_PI;
    }

    int get_wrap_count() const {
        return wrap_count;
    }

private:
    const int hard_encoder_max;
    const int counts_per_revolution;
    const double max_soft_encoder_value;

    int wrap_count;
    int prev_hard;
    double soft_encoder;
    int direction;
    bool initial_offset_set;
    int initial_offset;
};
