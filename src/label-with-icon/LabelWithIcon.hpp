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

#ifndef SHORTER_STATS_LABELWITHICON_HPP
#define SHORTER_STATS_LABELWITHICON_HPP

#include <QIcon>
#include <QLabel>
#include <QHBoxLayout>
#include "../icon-label/IconLabel.hpp"

class LabelWithIcon : public QWidget {
    Q_OBJECT

    private:
        IconLabel *icon = new IconLabel(this);
        QLabel *label = nullptr;
        QBoxLayout *layout = new QHBoxLayout(this);

    public:
        explicit LabelWithIcon(QWidget *parent, QLabel *label_);

    public Q_SLOTS:
        inline void setText(const QString &s) {
            label->setText(s);
        }
        inline void setIcon(const QIcon &newIcon, int iconSize) {
            icon->setIconSize(iconSize);
            icon->setIcon(newIcon);
        }
};

#endif //SHORTER_STATS_LABELWITHICON_HPP
