//
// Created by olivier on 18/07/26.
//

#ifndef TIMELINE_CONTROL_STR_UTIL_H
#define TIMELINE_CONTROL_STR_UTIL_H

#include <string>

inline double str_to_double(const std::string &str, const double default_ = 0.0) {
    try {
        return std::stod(str);
    }
    catch (std::exception &e) {
        return default_;
    }
}

inline int str_to_int(const std::string &str, const int default_ = 0) {
    try {
        return std::stoi(str);
    }
    catch (std::exception &e) {
        return default_;
    }
}

#endif //TIMELINE_CONTROL_STR_UTIL_H
