/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

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

class Ui_LoginWidget
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QStringLiteral("LoginWidget"));
        LoginWidget->resize(1000, 700);
        label = new QLabel(LoginWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 40, 371, 71));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        lineEdit = new QLineEdit(LoginWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(320, 150, 341, 51));
        QFont font1;
        font1.setPointSize(14);
        lineEdit->setFont(font1);
        lineEdit_2 = new QLineEdit(LoginWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 240, 341, 51));
        lineEdit_2->setFont(font1);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(LoginWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 240, 61, 51));
        QFont font2;
        font2.setPointSize(17);
        pushButton->setFont(font2);
        lineEdit_3 = new QLineEdit(LoginWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(320, 320, 221, 51));
        lineEdit_3->setFont(font1);
        pushButton_2 = new QPushButton(LoginWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 320, 101, 51));
        QFont font3;
        font3.setPointSize(15);
        pushButton_2->setFont(font3);
        pushButton_3 = new QPushButton(LoginWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 420, 141, 71));
        pushButton_3->setFont(font3);
        pushButton_4 = new QPushButton(LoginWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(430, 420, 141, 71));
        pushButton_4->setFont(font3);
        pushButton_5 = new QPushButton(LoginWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(610, 420, 141, 71));
        pushButton_5->setFont(font3);

        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LoginWidget", "360\345\272\246\346\231\272\350\203\275\350\241\214\350\275\246\350\276\205\345\212\251\347\263\273\347\273\237", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("LoginWidget", "\347\224\250\346\210\267\350\264\246\345\217\267\357\274\214\350\213\261\346\226\207/\346\225\260\345\255\2276\344\275\215", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("LoginWidget", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\214\350\213\261\346\226\207/\346\225\260\345\255\2276-10\344\275\215 ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LoginWidget", "*", Q_NULLPTR));
        lineEdit_3->setPlaceholderText(QApplication::translate("LoginWidget", "\351\252\214\350\257\201\347\240\201,\350\213\261\346\226\207/\346\225\260\345\255\2274\344\275\215", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LoginWidget", "8379", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("LoginWidget", "\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("LoginWidget", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("LoginWidget", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
