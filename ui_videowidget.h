/********************************************************************************
** Form generated from reading UI file 'videowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *VideoWidget)
    {
        if (VideoWidget->objectName().isEmpty())
            VideoWidget->setObjectName(QStringLiteral("VideoWidget"));
        VideoWidget->resize(1200, 700);
        pushButton = new QPushButton(VideoWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 20, 141, 51));
        pushButton_2 = new QPushButton(VideoWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 20, 201, 51));
        label = new QLabel(VideoWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 80, 840, 480));
        label->setScaledContents(true);
        label_2 = new QLabel(VideoWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 620, 91, 51));
        horizontalSlider = new QSlider(VideoWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(150, 570, 861, 41));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_3 = new QPushButton(VideoWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(550, 620, 101, 51));
        label_3 = new QLabel(VideoWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 620, 31, 51));
        label_4 = new QLabel(VideoWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 620, 21, 51));
        label_5 = new QLabel(VideoWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 620, 101, 51));

        retranslateUi(VideoWidget);

        QMetaObject::connectSlotsByName(VideoWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWidget)
    {
        VideoWidget->setWindowTitle(QApplication::translate("VideoWidget", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("VideoWidget", "\350\217\234\345\215\225\346\230\276\347\244\272", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("VideoWidget", "\346\210\252\345\233\276\347\211\271\345\276\201\350\256\260\345\275\225\344\270\212\344\274\240", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("VideoWidget", "\345\267\262\346\222\255\346\224\276", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("VideoWidget", "\346\222\255\346\224\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("VideoWidget", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("VideoWidget", "/", Q_NULLPTR));
        label_5->setText(QApplication::translate("VideoWidget", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoWidget: public Ui_VideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
