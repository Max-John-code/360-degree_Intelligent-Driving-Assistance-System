#ifndef BOOTWIDGET_H
#define BOOTWIDGET_H

#include <QWidget>
#include "Thread/decode.h"
#include <QPainter>
#include "mainwidget.h"

namespace Ui {
class BootWidget;
}

class BootWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BootWidget(QWidget *parent = nullptr);
    ~BootWidget();

private:
    Ui::BootWidget *ui;

    QImage image;

    Decode *decode;
    MainWidget *mainwidget;
    int count;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void receiveImg(QImage img, int current);
};

#endif // BOOTWIDGET_H
