#ifndef REGWIDGET_H
#define REGWIDGET_H

#include <QWidget>
#include "Thread/readthread.h"
#include "Thread/writethread.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QRegExp>
#include <QRegExpValidator>

namespace Ui {
class RegWidget;
}

class RegWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegWidget(QWidget *parent = nullptr);
    ~RegWidget();

    //MD5加密函数
    QString MD5Encryption(const QString &str);
    //清空编辑框
    void Clear();

    uint32_t crc32(const char *data, size_t size);

private slots:
//    void on_pushButton_2_clicked();

    //进行注册操作
    void on_pushButton_clicked();

    //注册成功返回登陆界面
    void successToLogin();
    void regFail();

private:
    Ui::RegWidget *ui;
    WriteThread* wth;
    ReadThread* rth;

    HEAD head;
    REG reg;

   char buf[200];

signals:
    void backToLogin(QString);
    void backToLogin2();
};

#endif // REGWIDGET_H
