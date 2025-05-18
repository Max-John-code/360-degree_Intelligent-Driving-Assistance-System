#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "Thread/readthread.h"
#include "Thread/writethread.h"
#include "view/regwidget.h"
#include <QMessageBox>
#include <QCryptographicHash>
#include <QTime>
#include <cstring>
#include <QRegExp>
#include <QRegExpValidator>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

    //MD5加密函数
    QString MD5Encryption(const QString &str);
    //清空编辑框
    void Clear();

private slots:
    void on_pushButton_3_clicked();

    //注册返回登陆界面
    void RegToLogin(QString);
    void RegToLogin2();
    void loginFail();
    //心跳断开回到设置界面重新连接
    void hreatLoss();

    void on_pushButton_4_clicked();

    //登陆成功去主界面
    void toMainWidget(QString username);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::LoginWidget *ui;
    WriteThread* wth;
    ReadThread* rth;
    RegWidget* regwidget;

    HEAD head;
    LOGIN login;
    char buf[200];
signals:
    void loginToMain(QString userid, QString username);
    //登录界面回到主界面
    void loginToSet();
};

#endif // LOGINWIDGET_H
