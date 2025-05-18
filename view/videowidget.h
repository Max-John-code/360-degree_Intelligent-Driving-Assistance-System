#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include "Thread/decode.h"
#include <QDateTime>
#include "Thread/splitfile.h"
#include "Thread/writethread.h"
#include <QFile>

namespace Ui {
class VideoWidget;
}

class VideoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoWidget( QWidget *parent = nullptr);
    ~VideoWidget();

    //设置播放视频的路径
    void setVideoPath(QString videoPath);

    void setUserid(const string &value);
    //设置显示封面
    void setCover(QString coverPath);
    //设置视频当前帧
    void setCurrentFrame(int value);
    //视频总帧数
    void setTotalFrame(int value);
    //视频时间
    void setDateTime(QString);
    //每次进去播放界面设置按钮为播放
    void PlayInit();

    void Sleep(int msec);//设置休眠

private:
    Ui::VideoWidget *ui;
    Decode *decode;

    QImage img;
    int currentFrame;
    //记录这个视频的日期
    QString dateTIme;
    //记录用户id
    string userid;
    PHOTO photo;    //第十五个协议，数据库存进数据库
    HEAD head;
    //视频进度更新
    SCHEDULE_SAVE scheduleSvae;

    SplitFile* splitTh;


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void receiveImg(QImage img, int currentFrame);
private slots:
    void on_pushButton_3_clicked();
    void on_horizontalSlider_sliderPressed();
    void on_horizontalSlider_sliderReleased();
    //接收视频线程finish的槽函数
//    void DecodeFinish();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    //点击显示菜单按钮发送返回的主界面
    void backToMain();
};

#endif // VIDEOWIDGET_H
