//
// Created by olivier on 18/07/26.
//

#ifndef TIMELINE_CONTROL_STR_UTIL_H
#define TIMELINE_CONTROL_STR_UTIL_H

#include <string>
#include <obs-module.h>
#include <QString>

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

inline std::string obs_module_file_std(const char *file) {
    char *file_ = obs_module_file(file);
    std::string out(file_);
    bfree(file_);
    return out;
}
inline QString obs_module_file_qt(const char *file) {
    char *file_ = obs_module_file(file);
    QString out(file_);
    bfree(file_);
    return out;
}

#endif //TIMELINE_CONTROL_STR_UTIL_H
