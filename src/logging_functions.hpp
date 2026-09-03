/******************************************************************************
    Copyright (C) 2023 by xurei <xureilab@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

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
