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

#include <QPlainTextEdit>
#include <QWidget>
#include <vector>
#include <obs-frontend-api.h>
#include <obs-module.h>
#include <plugin-support.h>
#include <QLabel>
#include <util/platform.h>
#include <QVBoxLayout>
#include "icon-label/IconLabel.hpp"

#ifndef SHORTER_STATS_OBSBASICSTATSITEM_HPP
#define SHORTER_STATS_OBSBASICSTATSITEM_HPP

class OBSBasicStatsItem : public QWidget {
    Q_OBJECT

    private:
        QLabel *field_label = new IconLabel(this);
        QBoxLayout *layout = new QHBoxLayout(this);
        QVBoxLayout *value_layout = new QVBoxLayout(this);

    public:
        explicit OBSBasicStatsItem(QString field_name, QString icon_path = "");

        //void setValue(const QString &field_value);

        void addValueWidget(QWidget *widget);

        //void setClass(const QString &newClasses);
};

#endif //SHORTER_STATS_OBSBASICSTATSITEM_HPP
