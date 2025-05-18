#include "decode.h"

Decode::Decode()
{
    this->isStop = true;
    this->isRun = false;
    this->sleep = 40;

    this->cap = new VideoCapture("./animation/boot.mp4");
    this->totalFrames = static_cast<int>(this->cap->get(CV_CAP_PROP_FRAME_COUNT));

    this->flag = 1;
}

bool Decode::getIsRun() const
{
    return isRun;
}

void Decode::setIsRun(bool value)
{
    isRun = value;
}

bool Decode::getIsStop() const
{
    return isStop;
}

void Decode::setIsStop(bool value)
{
    isStop = value;
}

void Decode::setVideoPath(QString filename)
{

    this->cap->open(filename.toStdString());
    //更改了播放的视频，总帧数也要更新
    this->totalFrames = static_cast<int>(this->cap->get(CV_CAP_PROP_FRAME_COUNT));
}

int Decode::getTotalFrames() const
{
    return totalFrames;
}

void Decode::setTotalFrames(int value)
{
    totalFrames = value;
}

void Decode::setCurrentFrame(int value)
{
    //根据当前帧数跳转画面
//    this->currentFrame = value;
//    this->cap->set(CV_CAP_PROP_POS_FRAMES, currentFrame);
//    cap->set(CV_CAP_PROP_POS_FRAMES, currentFrame);
//    qDebug() << "currentFrame = " << this->currentFrame;
//    this->currentFrame = static_cast<int>(this->cap->get(CV_CAP_PROP_POS_FRAMES));
//    qDebug() << "set get = " << this->currentFrame;


    this->currentFrame = value;
    cap->set(CV_CAP_PROP_POS_FRAMES, this->currentFrame);;

    msleep(1000);
    // 读取一帧以确保帧位置被正确设置
    cv::Mat tempFrame;
    if (!this->cap->read(tempFrame)) {
        qDebug() << "Failed to read frame";
    }

    qDebug() << "currentFrame = " << this->currentFrame;

    // 获取当前帧位置，确保位置正确
//    this->currentFrame = static_cast<int>(this->cap->get(CV_CAP_PROP_POS_FRAMES));
//    qDebug() << "set get = " << this->currentFrame;
}

void Decode::setFlag(int value)
{
    flag = value;
}

void Decode::setSleep(unsigned long value)
{
    sleep = value;
}

void Decode::run()
{
    while (!(this->isStop)) {
        if(this->isRun)
        {

            this->cap->read(this->frame);
            if (this->frame.empty())
            {
//                emit this->finished();
                qDebug() << "finish" ;
                break;
            }
            this->img = QImage(frame.data, frame.cols, frame.rows, frame.cols*frame.channels(), QImage::Format_RGB888);
            //获取当前帧数
            this->currentFrame = static_cast<int>(this->cap->get(CV_CAP_PROP_POS_FRAMES));
//            qDebug() << "currentFrame = " << currentFrame++;

            if(this->flag==1)
                emit this->sendImg(this->img, this->currentFrame);
            else if(this->flag==2)
                emit sendMat(this->frame.clone());
            msleep(30);

            msleep(this->sleep);
        }
    }
    this->cap->release();
    msleep(1000);
//    this->cap = new VideoCapture;
//    this->terminate();
}
