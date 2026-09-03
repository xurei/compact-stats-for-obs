//
// Created by olivier on 3/09/26.
//

#include "OBSBasicStatsItem.hpp"
#include "qt-wrappers.hpp"
#include <QVBoxLayout>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "MemoryLeak"
OBSBasicStatsItem::OBSBasicStatsItem(const QString field_name, const QString icon_path) : QWidget(nullptr) {
    this->setLayout(layout);
    layout->addWidget(field_label, 0, Qt::AlignRight);
    field_label->setContentsMargins(0, 0, 10, 0);
    layout->addLayout(value_layout, 2);
    //layout->addWidget(value_label, 1, Qt::AlignHCenter);
    if (icon_path != "") {
        ((IconLabel*)field_label)->setIconSize(26);
        ((IconLabel*)field_label)->setIcon(QIcon(icon_path));
        field_label->setToolTip(field_name);
    }
    else {
        field_label = new QLabel(this);
        field_label->setText(field_name);
    }
    this->setToolTip(field_name);

//    value_label->setText("-");
//    value_label->setToolTip(field_name);
}
#pragma clang diagnostic pop

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
