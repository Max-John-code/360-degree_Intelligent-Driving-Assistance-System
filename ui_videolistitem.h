/********************************************************************************
** Form generated from reading UI file 'videolistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOLISTITEM_H
#define UI_VIDEOLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoListItem
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QWidget *VideoListItem)
    {
        if (VideoListItem->objectName().isEmpty())
            VideoListItem->setObjectName(QStringLiteral("VideoListItem"));
        VideoListItem->resize(350, 180);
        VideoListItem->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(VideoListItem);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 165, 321, 31));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(VideoListItem);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 130, 131, 51));
        QFont font1;
        font1.setPointSize(16);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label = new QLabel(VideoListItem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 341, 131));
        label->setScaledContents(true);

        retranslateUi(VideoListItem);

        QMetaObject::connectSlotsByName(VideoListItem);
    } // setupUi

    void retranslateUi(QWidget *VideoListItem)
    {
        VideoListItem->setWindowTitle(QApplication::translate("VideoListItem", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("VideoListItem", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("VideoListItem", "TextLabel", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoListItem: public Ui_VideoListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOLISTITEM_H
