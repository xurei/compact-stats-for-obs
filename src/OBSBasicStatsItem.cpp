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

#include "OBSBasicStatsItem.hpp"
#include "qt-wrappers.hpp"
#include <QVBoxLayout>

#ifdef __clang__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemoryLeak"
#endif
OBSBasicStatsItem::OBSBasicStatsItem(const QString field_name, const QString icon_path) : QWidget(nullptr) {
    this->setLayout(layout);
    layout->addWidget(field_label, 0, Qt::AlignRight);
    field_label->setContentsMargins(0, 0, 10, 0);
    layout->addLayout(value_layout, 2);
    if (icon_path != "") {
        ((IconLabel*)field_label)->setIconSize(28);
        ((IconLabel*)field_label)->setIcon(QIcon(icon_path));
        field_label->setToolTip(field_name);
    }
    else {
        field_label = new QLabel(this);
        field_label->setText(field_name);
    }
    if (field_name != "") {
        this->setToolTip(field_name);
    }
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif

void OBSBasicStatsItem::addValueWidget(QWidget *widget) {
    value_layout->addWidget(widget, 1, Qt::AlignLeft);
}

//void OBSBasicStatsItem::setValue(const QString &field_value) {
//    value_label->setText(field_value);
//    value_label->setProperty("class", this->property("class"));
//}

//void OBSBasicStatsItem::setClass(const QString &newClasses) {
//    setClasses(value_label, newClasses);
//}
