/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QWidget *widget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QListWidget *listWidget;
    QWidget *page_2;
    QLabel *label_3;
    QWidget *page_3;
    QLabel *label_5;
    QPushButton *pushButton_8;
    QWidget *page_4;
    QLabel *label_2;
    QLabel *label_16;
    QWidget *page_5;
    QListWidget *listWidget_2;
    QWidget *widget_2;
    QPushButton *pushButton_9;
    QLabel *label_4;
    QLabel *label_6;
    QWidget *page_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_5;
    QLabel *label_13;
    QLineEdit *lineEdit_6;
    QLabel *label_14;
    QLabel *label_15;
    QCheckBox *checkBox;
    QPushButton *pushButton_10;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1200, 700);
        widget = new QWidget(MainWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 0, 281, 701));
        widget->setStyleSheet(QStringLiteral(""));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(46, 26, 211, 31));
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 90, 89, 25));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 130, 251, 41));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 190, 251, 41));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 240, 251, 41));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 290, 251, 41));
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 340, 251, 41));
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 390, 251, 41));
        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(350, 0, 831, 700));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        listWidget = new QListWidget(page);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(40, 60, 800, 600));
        listWidget->setBatchSize(97);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 800, 551));
        label_3->setScaledContents(true);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 90, 800, 551));
        label_5->setScaledContents(true);
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(50, 20, 121, 41));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 40, 291, 601));
        label_2->setScaledContents(true);
        label_16 = new QLabel(page_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(336, 40, 501, 601));
        label_16->setScaledContents(true);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        listWidget_2 = new QListWidget(page_5);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(0, 60, 830, 601));
        listWidget_2->setIconSize(QSize(250, 200));
        listWidget_2->setSpacing(10);
        listWidget_2->setViewMode(QListView::IconMode);
        widget_2 = new QWidget(page_5);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 851, 691));
        widget_2->setStyleSheet(QStringLiteral("background-color: white;"));
        pushButton_9 = new QPushButton(widget_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(20, 10, 131, 51));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 80, 811, 471));
        label_4->setScaledContents(true);
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 590, 711, 81));
        QFont font;
        font.setPointSize(30);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_7 = new QLabel(page_6);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 50, 741, 101));
        QFont font1;
        font1.setPointSize(22);
        label_7->setFont(font1);
        label_8 = new QLabel(page_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 160, 141, 51));
        QFont font2;
        font2.setPointSize(22);
        font2.setBold(false);
        font2.setWeight(50);
        label_8->setFont(font2);
        lineEdit = new QLineEdit(page_6);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 160, 111, 41));
        lineEdit_2 = new QLineEdit(page_6);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 160, 111, 41));
        lineEdit_3 = new QLineEdit(page_6);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(460, 160, 111, 41));
        lineEdit_4 = new QLineEdit(page_6);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(610, 160, 111, 41));
        label_9 = new QLabel(page_6);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(300, 170, 31, 31));
        QFont font3;
        font3.setPointSize(22);
        font3.setBold(true);
        font3.setWeight(75);
        label_9->setFont(font3);
        label_10 = new QLabel(page_6);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(440, 170, 31, 31));
        label_10->setFont(font3);
        label_11 = new QLabel(page_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(580, 170, 31, 31));
        label_11->setFont(font3);
        label_12 = new QLabel(page_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 230, 231, 51));
        label_12->setFont(font2);
        lineEdit_5 = new QLineEdit(page_6);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(270, 240, 450, 41));
        label_13 = new QLabel(page_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 310, 261, 51));
        label_13->setFont(font2);
        lineEdit_6 = new QLineEdit(page_6);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(310, 310, 141, 41));
        label_14 = new QLabel(page_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(470, 320, 101, 41));
        label_15 = new QLabel(page_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 380, 351, 51));
        QFont font4;
        font4.setPointSize(22);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        label_15->setFont(font4);
        checkBox = new QCheckBox(page_6);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(400, 380, 161, 51));
        checkBox->setFont(font2);
        checkBox->setChecked(false);
        pushButton_10 = new QPushButton(page_6);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(250, 500, 171, 71));
        QFont font5;
        font5.setPointSize(16);
        pushButton_10->setFont(font5);
        stackedWidget->addWidget(page_6);

        retranslateUi(MainWidget);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("MainWidget", "\346\234\252\347\231\273\345\275\225\347\224\250\346\210\267", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWidget", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWidget", "\350\247\206\351\242\221\350\256\260\345\275\225", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWidget", "\350\241\214\350\275\246\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWidget", "\345\200\222\350\275\246\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWidget", "\351\270\237\347\236\260\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWidget", "\347\211\271\345\276\201\350\256\260\345\275\225", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\350\256\276\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWidget", "l", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWidget", "daochemoshi", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWidget", "\346\230\276\347\244\272\350\217\234\345\215\225", Q_NULLPTR));
        label_2->setText(QString());
        label_16->setText(QString());
        pushButton_9->setText(QApplication::translate("MainWidget", "\350\277\224\345\233\236", Q_NULLPTR));
        label_4->setText(QString());
        label_6->setText(QString());
        label_7->setText(QApplication::translate("MainWidget", "\345\275\223\345\211\215\347\263\273\347\273\237\347\211\210\346\234\254\357\274\232 360\345\272\246\346\231\272\350\203\275\350\241\214\350\275\246\350\276\205\345\212\251\347\263\273\347\273\237 v1.0", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWidget", "\346\234\215\345\212\241\345\231\250IP\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWidget", ".", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWidget", ".", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWidget", ".", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWidget", "\346\234\215\345\212\241\345\231\250\347\263\273\347\273\237\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWidget", "\346\234\254\345\234\260\347\263\273\347\273\237\345\255\230\345\202\250\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWidget", "GB", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWidget", "\346\234\254\345\234\260\347\263\273\347\273\237\346\230\257\345\220\246\345\217\257\350\207\252\345\212\250\345\210\240\351\231\244\357\274\232", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWidget", "\350\207\252\345\212\250\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWidget", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
