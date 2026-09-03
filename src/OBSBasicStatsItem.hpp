//
// Created by olivier on 3/09/26.
//

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
