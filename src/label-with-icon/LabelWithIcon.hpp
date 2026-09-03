//
// Created by olivier on 3/09/26.
//

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
