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

#ifndef TIMELINE_CONTROL_STR_UTIL_H
#define TIMELINE_CONTROL_STR_UTIL_H

#include <string>
#include <obs-module.h>
#include <QString>

inline QString obs_module_file_qt(const char *file) {
    char *file_ = obs_module_file(file);
    QString out(file_);
    bfree(file_);
    return out;
}

#endif //TIMELINE_CONTROL_STR_UTIL_H
