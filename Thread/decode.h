#ifndef DECODE_H
#define DECODE_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <QString>
#include <QImage>
#include <QDebug>

using namespace cv;

class Decode : public QThread
{
    Q_OBJECT
public:
    Decode();

    bool getIsRun() const;
    void setIsRun(bool value);

    bool getIsStop() const;
    void setIsStop(bool value);

    //设置视频路径
    void setVideoPath(QString filename);

    int getTotalFrames() const;
    void setTotalFrames(int value);

    //设置视频当前帧
    void setCurrentFrame(int value);

    void setFlag(int value);

    void setSleep(unsigned long value);

private:
    unsigned long sleep;
    bool isRun;
    bool isStop;

    Mat frame;
    VideoCapture *cap;

    QImage img;

    //总帧数
    int totalFrames;
    //当前帧数
    int currentFrame;

    int flag;

    // QThread interface
protected:
    void run();

signals:
    //画面和帧数
    void sendImg(QImage, int);
    void sendMat(Mat);
    //finished
//    void finished();
};

#endif // DECODE_H
