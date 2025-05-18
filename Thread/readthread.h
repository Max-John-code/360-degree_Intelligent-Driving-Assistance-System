#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>
#include  "protocol.h"
#include <QDebug>
#include <unistd.h>
#include <string.h>
#include <QMessageBox>
Q_DECLARE_METATYPE(GET_PHOTOS_INFO)
Q_DECLARE_METATYPE(FILE_LOSS)
Q_DECLARE_METATYPE(BACK_PAGE)

class ReadThread : public QThread
{
    Q_OBJECT
public:
    static ReadThread* getInstance();
    static ReadThread* rth;

    int getRfd() const;
    void setRfd(int value);

private:
    ReadThread();

    HEAD head;
//    LOGIN login;
    LOGIN_BACK loginBack;   //登录返回协议体
    TBACK tback;            //注册返回协议体
    FILE_LOSS fileLoss;     //图片丢失返回协议体
    GET_PHOTOS_INFO photoInfo;  //图片信息返回包
    BACK_PAGE backPage;     //视频翻页返回协议体
    char buf[2000];

    int res;
    int rfd;

    // QThread interface
protected:
    void run();

signals:
    //登陆成功带有用户名
    void loginSuccess(QString);
    //登陆账号密码错误
    void loginFail();
    void regSuccess();
    void regFail();
    //心跳被断开连接
    void heartLoss();
    //告诉图片发送成功
    void emitPhotoSuccess();
    //特征记录界面显示图片
    void getPhoto(GET_PHOTOS_INFO);
    //发送丢包信息给文件拆分线程
    void packLoss(FILE_LOSS);
    //发送整个翻页返回协议体给给视频数据展示列表
    void emitBackPage(BACK_PAGE);
    void setFail();
};

#endif // READTHREAD_H
