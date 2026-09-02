#ifndef SHADERTASTIC_LOGGING_FUNCTIONS_HPP
#define SHADERTASTIC_LOGGING_FUNCTIONS_HPP

#include <obs-module.h>

#define do_log(level, format, ...) \
    blog(level, "[shorter-stats] " format, ##__VA_ARGS__)
#define info(format, ...) do_log(LOG_INFO, format, ##__VA_ARGS__)
#define warn(format, ...) do_log(LOG_WARNING, format, ##__VA_ARGS__)
#define log_error(format, ...) do_log(LOG_ERROR, format, ##__VA_ARGS__)

#ifdef DEV_MODE
    #define debug(format, ...) info("(debug) " #format, ##__VA_ARGS__)
#else
    #define debug(format, ...)
#endif
#define debug_trace(format, ...) //debug(format, ##__VA_ARGS__)

#endif // SHADERTASTIC_LOGGING_FUNCTIONS_HPP
