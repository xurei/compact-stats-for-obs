//
// Created by olivier on 3/09/26.

#include "LabelWithIcon.hpp"

LabelWithIcon::LabelWithIcon(QWidget *parent, QLabel *label_) : QWidget(parent), label(label_) {
    this->setLayout(layout);
    layout->setSpacing(2);
    layout->addWidget(icon, 0);
    layout->addWidget(label, 1);
    this->setContentsMargins(0, 0, 0, 0);
    layout->setContentsMargins(0, 0, 0, 0);
    icon->setContentsMargins(0, 0, 0, 0);
    label->setContentsMargins(0, 0, 0, 0);
}
