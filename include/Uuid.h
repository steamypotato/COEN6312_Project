//
// Created by Hoopa on 2/27/2025.
//

#ifndef UUID_H
#define UUID_H
#include <iomanip>
#include <random>
#include <sstream>

namespace utils {
    static time_t getEpochFromTimeString(const std::string& timeStr) {
        std::tm tm = {};
        // Get the current date (in local time) to use as a base.
        time_t now = time(nullptr);
        tm = *std::localtime(&now);

        // Parse the time string to update the hours and minutes.
        std::istringstream iss(timeStr);
        iss >> std::get_time(&tm, "%H:%M");


        // mktime converts tm (interpreted as local time) into epoch time.
        return std::mktime(&tm);
    }
}


namespace uuid {
    static std::random_device              rd;
    static std::mt19937                    gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    static std::string generate_uuid_v4() {
        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };
        return ss.str();
    }
}

#endif //UUID_H
