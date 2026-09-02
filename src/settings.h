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
