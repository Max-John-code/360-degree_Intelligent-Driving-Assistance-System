#ifndef CAMDECODE_H
#define CAMDECODE_H

#include <QThread>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <QDebug>
#include <iostream>
#include <QDateTime>
#include <QMessageBox>
#include "protocol.h"
#include "Thread/writethread.h"
#include "Thread/splitfile.h"

using namespace cv;
using namespace std;

class CamDecode : public QThread
{
    Q_OBJECT
public:
    static CamDecode* getInstance();
    static CamDecode* camth;
    bool getIsRun() const;
    void setIsRun(bool value);

    bool getIsStop() const;
    void setIsStop(bool value);

    //红绿灯检测
    // Function headers
    int processImgR(Mat);
    int processImgG(Mat);
    bool isIntersected(Rect, Rect);
    //执行红绿灯检测的函数
    void lightDetect(Mat &frame);
    //倒车模式距离检测函数
    void ObstacleRanging(Mat &frame);

    //级联分类器函数
    void detecCarRaw(Mat &frame, double scale);
    //设置视频路径    实际应该是改变摄像头
    void setVideoPath(QString filename);
    //这个函数用于自动上传截图
    void autoPhoto();

    bool getIsRecord() const;
    void setIsRecord(bool value);

    void setFlag(int value);

    string getUserid() const;
    void setUserid(const string &value);

    //主界面窗口关闭时需要做的操作
    void MainClose();
    void swapWindow();

private:
    bool isRun;
    bool isStop;
    //录制
    bool isRecord;

    SplitFile *splite;

    //用来区分模式，1行车，2倒车，3鸟瞰
    int flag;
    Mat frame;
    VideoCapture *cap;
    QImage img;

    VideoWriter write;
    //红绿灯检测
    // Global variables
    bool isFirstDetectedR;
    bool isFirstDetectedG;
    Rect* lastTrackBoxR;
    Rect* lastTrackBoxG;
    int lastTrackNumR;
    int lastTrackNumG;
    //倒车模式的私有定义
    bool a;
    int i;

    //级联分类器
    CascadeClassifier cascade;

    //记录录制的帧数
    int recordNum;
    QString current_date;
    QString filename;
    string coverPath;

    //录制完成帧数
    int totalFrame;

    string userid;

    VIDEO_SAVE videoSave;    //告诉服务器保存的视频信息协议体
    HEAD head;
    PHOTO photo;

    CamDecode();

    // QThread interface
protected:
    void run();
signals:
    //实时播放只传一个画面，所以只有一个QImage
    void sendImg(QImage);
    void sendMat(Mat);
    //录制完发送信号告诉开始计时10秒
    void TimeStart();
};

#endif // CAMDECODE_H
