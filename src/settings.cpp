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

#include <util/platform.h>

#include "version.h"
#include "settings.h"
#include "logging_functions.hpp"
#include "plugin-common.h"

//settings_t plugin_settings_;
obs_data_t *current_settings_data_ = nullptr;
//----------------------------------------------------------------------------------------------------------------------

obs_data_t * plugin_settings() {
//  if (current_settings_data_ == nullptr) {
//    current_settings_data_ = load_settings();
//  }
  return current_settings_data_;
}
void set_plugin_settings(obs_data_t *settings) {
    release_resource(obs_data_release, current_settings_data_);
    current_settings_data_ = settings;
    /*if (current_settings_data_ == nullptr) {
        current_settings_data_ = load_settings();
    }*/
}
//----------------------------------------------------------------------------------------------------------------------

#ifndef _WIN32
#pragma clang diagnostic pop
#endif
