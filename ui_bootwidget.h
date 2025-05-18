/********************************************************************************
** Form generated from reading UI file 'bootwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOTWIDGET_H
#define UI_BOOTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BootWidget
{
public:

    void setupUi(QWidget *BootWidget)
    {
        if (BootWidget->objectName().isEmpty())
            BootWidget->setObjectName(QStringLiteral("BootWidget"));
        BootWidget->resize(1200, 700);

        retranslateUi(BootWidget);

        QMetaObject::connectSlotsByName(BootWidget);
    } // setupUi

    void retranslateUi(QWidget *BootWidget)
    {
        BootWidget->setWindowTitle(QApplication::translate("BootWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BootWidget: public Ui_BootWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOTWIDGET_H
