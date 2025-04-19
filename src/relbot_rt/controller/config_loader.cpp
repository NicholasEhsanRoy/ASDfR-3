#include "pid_config.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool ConfigLoader::load(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error opening config file: " << filepath << "\n";
        return false;
    }

    pid_configs_.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        std::vector<double> values;

        while (std::getline(ss, value, ',')) {
            try {
                values.push_back(std::stod(value));
            } catch (...) {
                std::cerr << "Invalid number in config: " << value << "\n";
                return false;
            }
        }

        if (values.size() != 3) {
            std::cerr << "Each line must have exactly 3 values (Kp, Ki, Kd)\n";
            return false;
        }

        pid_configs_.emplace_back(PIDConfig{values[0], values[1], values[2]});
    }

    return true;
}

const std::vector<PIDConfig>& ConfigLoader::get_configs() const {
    return pid_configs_;
}
