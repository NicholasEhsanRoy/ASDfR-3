#pragma once
#include <vector>
#include <string>

struct PIDConfig {
    double kp;
    double ki;
    double kd;
};

class ConfigLoader {
public:
    bool load(const std::string& filepath);
    const std::vector<PIDConfig>& get_configs() const;

private:
    std::vector<PIDConfig> pid_configs_;
};
