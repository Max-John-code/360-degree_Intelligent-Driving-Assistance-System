#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDebug>
#include "videolistitem.h"
#include <QListWidget>
#include "videowidget.h"
#include "Thread/camdecode.h"
#include <QTimer>
#include <QListWidgetItem>
#include <iostream>
#include "protocol.h"
#include "Thread/readthread.h"
#include "Thread/writethread.h"
#include <QScrollBar>
#include "socketconnect.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "loginwidget.h"
#include "Thread/splitfile.h"
#include "Thread/heartbeatthread.h"

#include "Thread/decode.h"
#include <opencv2/opencv.hpp>
#include <algorithm>

using namespace cv;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
//    void Sleep(int msec);

private:
    Ui::MainWidget *ui;
    WriteThread *wth;
    ReadThread *rth;
    SocketConnect *sc;
    SplitFile *splitTh;
    HeartbeatThread * heatrTh;

    QImage img, img2;
    int imgIndex;   //特征图片index
    int videoIndex;

    LoginWidget *loginwidget;
    VideoWidget *videowidget;   //用于数据列表展示的封装widget

    QListWidgetItem * listwidgetItem;   //特征记录界面的item
    QScrollBar *vScrollBar;         //数据列表滚动条
    QScrollBar *vScrollBar2;        //特征记录滚动条

    CamDecode *camdecode;
    // 创建一个QTimer对象
    QTimer *timer;  //定时器指针
    QTimer *timer2; //

    //用户id
    string userid;
    //账号
    string account;

    HEAD head;
    //图片查询协议体
    TURN_PICTURE pictrue;
    //视频查询协议体（视频翻页协议体）
    TURN_PAGE videoSearch;

    Mat mat1, mat2;
    Decode *decode;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void onTimeout();   //定时器槽函数
    void onTimeout2();
    void CountTenTime();    //启动计时10秒的函数
    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    //设置界面网络配置失败
    void setFail();
    void setSuccess();
    //登录界面回到设置界面
    void loginToSet();
    //登陆界面回到主界面
    void loginBackToMain(QString userid, QString username);
    //去到场景重现界面
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    //从场景重现界面返回来
    void VideoBackTOMain();

    //行车模式接收解码线程传来的图片
    void receiveImg(QImage);
    //鸟瞰模式
    void receiveMat1(Mat);
    void receiveMat2(Mat);

    //read线程读完后显示特征记录图片
    void ShowPhoto(GET_PHOTOS_INFO);
    //read线程读完后显示视频列表
    void showVideo(BACK_PAGE);

    void onScrollBarValueChanged(int);
    void onScrollBarValueChanged2(int);
    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);
    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    // QWidget interface
    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWIDGET_H
