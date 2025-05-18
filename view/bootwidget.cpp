#include "bootwidget.h"
#include "ui_bootwidget.h"

BootWidget::BootWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BootWidget)
{
    ui->setupUi(this);
    this->count = 0;

    this->decode = new Decode;
//    this->decode->setVideoPath("./animation/boot.mp4");
    this->decode->setIsRun(true);
    this->decode->setIsStop(false);
    this->decode->setSleep(33);
    connect(this->decode, SIGNAL(sendImg(QImage, int)), this, SLOT(receiveImg(QImage, int)), Qt::BlockingQueuedConnection);
    this->decode->start();
    this->mainwidget = new MainWidget;
}

BootWidget::~BootWidget()
{
    delete ui;
}

void BootWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    //画笔对象
    QPainter paint(this);
    //判断Image是不是空的
    if(!this->image.isNull())
    {
        paint.drawImage(QRect(0, 0, 1200,700), this->image.rgbSwapped());
    }
}

void BootWidget::receiveImg(QImage img, int current)
{
    Q_UNUSED(current);
    this->image = img;
    update();
    this->count++;
    if(this->count==this->decode->getTotalFrames())
    {
        //播放完之后就可以让这个线程结束了
        this->decode->setIsStop(true);
        //开机动画播放完之后，就再也不用了，断开这个连接
        disconnect(this->decode, SIGNAL(sendImg(QImage, int)), this, SLOT(receiveImg(QImage, int)));
        this->close();
        this->mainwidget->show();
    }

}
