/********************************************************************************
** Form generated from reading UI file 'regwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWIDGET_H
#define UI_REGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegWidget
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *RegWidget)
    {
        if (RegWidget->objectName().isEmpty())
            RegWidget->setObjectName(QStringLiteral("RegWidget"));
        RegWidget->resize(1000, 700);
        label = new QLabel(RegWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 30, 351, 101));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        lineEdit = new QLineEdit(RegWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(320, 150, 341, 51));
        QFont font1;
        font1.setPointSize(14);
        lineEdit->setFont(font1);
        lineEdit_2 = new QLineEdit(RegWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 230, 341, 51));
        lineEdit_2->setFont(font1);
        lineEdit_3 = new QLineEdit(RegWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(320, 310, 341, 51));
        lineEdit_3->setFont(font1);
        lineEdit_3->setEchoMode(QLineEdit::Password);
        lineEdit_4 = new QLineEdit(RegWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(320, 390, 341, 51));
        lineEdit_4->setFont(font1);
        lineEdit_4->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(RegWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 500, 171, 71));
        QFont font2;
        font2.setPointSize(15);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(RegWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 500, 171, 71));
        pushButton_2->setFont(font2);

        retranslateUi(RegWidget);

        QMetaObject::connectSlotsByName(RegWidget);
    } // setupUi

    void retranslateUi(QWidget *RegWidget)
    {
        RegWidget->setWindowTitle(QApplication::translate("RegWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("RegWidget", "360\345\272\246\346\231\272\350\203\275\350\241\214\350\275\246\350\276\205\345\212\251\347\263\273\347\273\237", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("RegWidget", "\347\224\250\346\210\267\350\264\246\345\217\267\357\274\214\350\213\261\346\226\207/\346\225\260\345\255\2276\344\275\215", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("RegWidget", "\346\230\265\347\247\260/\347\224\250\346\210\267\345\220\215\357\274\214\350\213\261\346\226\207/\346\225\260\345\255\2276-8\344\275\215 ", Q_NULLPTR));
        lineEdit_3->setPlaceholderText(QApplication::translate("RegWidget", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\214\350\213\261\346\226\207/\346\225\260\345\255\2276-10\344\275\215 ", Q_NULLPTR));
        lineEdit_4->setPlaceholderText(QApplication::translate("RegWidget", "\351\207\215\345\244\215\345\257\206\347\240\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RegWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("RegWidget", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegWidget: public Ui_RegWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWIDGET_H
