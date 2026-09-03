/**
Plugin Name
Copyright (C) <Year> <Developer> <Email Address>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>
*/

#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>
#include <obs-frontend-api.h>
#include <obs-module.h>
#include <plugin-support.h>
#include <QLabel>
#include <util/platform.h>

#include "settings.h"
#include "logging_functions.hpp"
#include "OBSBasicStats.hpp"

OBS_DECLARE_MODULE()

OBS_MODULE_USE_DEFAULT_LOCALE(PLUGIN_NAME, "en-US")

class QDockDataItem : public QWidget {
    Q_OBJECT

    private:
        QLabel *field_label = new QLabel();
        QLabel *value_label = new QLabel();

    public:
        #pragma clang diagnostic push
        #pragma ide diagnostic ignored "MemoryLeak"
        explicit QDockDataItem(const QString &field_name) : QWidget(nullptr) {
            auto *layout = new QVBoxLayout();
            this->setLayout(layout);
            layout->addWidget(field_label, 1, Qt::AlignHCenter);
            layout->addWidget(value_label, 1, Qt::AlignHCenter);
            this->setMaximumHeight(50);

            field_label->setText(field_name);
            value_label->setText("-");
        }
        #pragma clang diagnostic pop


        void setValue(const QString &field_value) {
            value_label->setText(field_value);
        }
};

class MyDock : public QWidget {
    Q_OBJECT

    private:
        QDockDataItem *cpu_data_item;
        QDockDataItem *fps_data_item;

    public:
        #pragma clang diagnostic push
        #pragma ide diagnostic ignored "MemoryLeak"
        explicit MyDock(QWidget *parent = nullptr) : QWidget(parent) {
            auto *layout = new QGridLayout(this);
            //auto *layout = new QHBoxLayout(this);
            this->setLayout(layout);


            cpu_data_item = new QDockDataItem("CPU");
            fps_data_item = new QDockDataItem("Frame time & FPS");

            //os_cpu_usage_info_t cpu_info;


            layout->addWidget(cpu_data_item, 0, 0);
            layout->addWidget(fps_data_item, 0, 1);
            auto *play_button = new QPushButton("Play", this);
            layout->addWidget(play_button);

            //auto *layout_status = new QHBoxLayout(this);
//            auto *layout_buttons = new QHBoxLayout(this);
//            auto *play_button = new QPushButton("Play", this);
//            auto *step_button = new QPushButton("Step", this);
//            auto *reset_button = new QPushButton("Reset", this);
//            text_area->setMinimumHeight(300);
//            QFont font;
//            font.setFamily(QFontDatabase::systemFont(QFontDatabase::FixedFont).family());
//            text_area->setFont(font);
//            text_area->setStyleSheet("font-family: monospace; font-size: 14px");
//
//            layout_buttons->addWidget(step_button);
//            layout_buttons->addWidget(play_button);
//            layout_buttons->addWidget(reset_button);
//            layout->addWidget(text_area);
//            layout->addLayout(layout_buttons);
//            this->setLayout(layout);
//
//            statusLabel = new QLabel(this);
//            layout_status->addWidget(statusLabel);
//            layout->addLayout(layout_status);

//            QObject::connect(reset_button, &QPushButton::clicked, this, [this]() {
//                resetActions.resetTime();
//                resetActions.play([this] {
//                    this->statusLabel->setText("");
//                });
//            });
//
//            QObject::connect(play_button, &QPushButton::clicked, this, [this]() {
//                timelineActions.resetTime();
//                statusLabel->setText("▶ Playing...");
//                timelineActions.play([this] {
//                    this->statusLabel->setText("");
//                });
//            });
        }
        #pragma clang diagnostic pop
};

OBSBasicStats *stats_dock;

void obs_module_load_docks() {
    //auto *settings = plugin_settings();
}
void obs_module_unload_docks() {
    /* nothing to do */
}

//void obs_module_frontend_saveload(obs_data_t *save_data, bool saving, void *data) {
//    UNUSED_PARAMETER(data);
//    auto *def_obj = obs_data_create();
//    obs_data_set_default_obj(save_data, PLUGIN_NAME, def_obj);
//    obs_data_release(def_obj);
//    auto plugin_settings_ = obs_data_get_obj(save_data, PLUGIN_NAME);
//
//    if (saving) {
//        auto *settings = plugin_settings();
//        obs_data_set_obj(save_data, PLUGIN_NAME, settings);
//        debug("saved settings");
////        set_plugin_settings
////            obs_data_get_array(settings, SETTING_EFFECTS_PATHS);
////        //quickAccessUtility->Save(save_data);
//    }
//    else {
//        if (plugin_settings_ == nullptr) {
//            return; // Should not happen anyway
//        }
//
//        obs_module_unload_docks();
//
//        debug("load settings: %s", obs_data_get_json(plugin_settings_));
//        const char *tmp = obs_data_get_json(plugin_settings_);
//        auto *cloned_settings = obs_data_create_from_json(tmp);
//        set_plugin_settings(cloned_settings);
//        obs_module_load_docks();
//        //quickAccessUtility->Load(save_data);
//    }
//}

[[maybe_unused]]
bool obs_module_load(void) {
    stats_dock = new OBSBasicStats();
    obs_frontend_add_dock_by_id("xureilab-shorter-stats", "Shorter Stats", stats_dock);
//    obs_frontend_add_save_callback(obs_module_frontend_saveload, nullptr);
    return true;
}

[[maybe_unused]]
void obs_module_unload(void) {
//    stats_dock->deleteLater();
//    stats_dock = nullptr;

    /*if (g_dock != nullptr) {
        g_dock->deleteLater();
        g_dock = nullptr;
    }*/
    obs_frontend_remove_dock("xureilab-shorter-stats");
    obs_log(LOG_INFO, "plugin unloaded");
}

#include "plugin-main.moc"
