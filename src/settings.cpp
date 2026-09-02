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
