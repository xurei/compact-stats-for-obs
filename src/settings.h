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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <obs-module.h>
#include <string>
#include <vector>

struct settings_t {
    // Path where the user can add their own effects
    std::vector<std::string> effects_paths;
    bool dev_mode_enabled = false;
    bool one_euro_enabled = false;
    float one_euro_min_cutoff = 10.0f;
    float one_euro_deriv_cutoff = 0.007f;
    float one_euro_beta = 10.0f;
};
//----------------------------------------------------------------------------------------------------------------------

obs_data_t * load_settings();

void save_settings(obs_data_t *settings);

void apply_settings(obs_data_t *settings);

obs_data_t * plugin_settings();
void set_plugin_settings(obs_data_t *settings);

void show_settings_dialog();

#endif // SETTINGS_H
