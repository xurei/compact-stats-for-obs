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

#include <vector>
#include <obs-frontend-api.h>
#include <obs-module.h>
#include <plugin-support.h>
#include <util/platform.h>

#include "OBSBasicStats.hpp"

OBS_DECLARE_MODULE()

OBS_MODULE_USE_DEFAULT_LOCALE(PLUGIN_NAME, "en-US")

OBSBasicStats *stats_dock;

void obs_module_load_docks() {
    //auto *settings = plugin_settings();
}
void obs_module_unload_docks() {
    /* nothing to do */
}

[[maybe_unused]]
bool obs_module_load(void) {
    stats_dock = new OBSBasicStats();
    obs_frontend_add_dock_by_id("xureilab-shorter-stats", "Shorter Stats", stats_dock);
//    obs_frontend_add_save_callback(obs_module_frontend_saveload, nullptr);
    return true;
}

[[maybe_unused]]
void obs_module_unload(void) {
    obs_frontend_remove_dock("xureilab-shorter-stats");
    obs_log(LOG_INFO, "plugin unloaded");
}

#include "plugin-main.moc"
