#include "videowidget.h"
#include "ui_videowidget.h"

VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWidget)
{
    ui->setupUi(this);

    this->currentFrame = 0;

    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setMinimum(0);

    //单步步长
    ui->horizontalSlider->setSingleStep(1);

    this->splitTh = SplitFile::getInstance();
}

VideoWidget::~VideoWidget()
{
    delete ui;
}


void VideoWidget::setVideoPath(QString videoPath)
{
    this->decode = new Decode;
    this->decode->setIsStop(false);
    this->decode->setIsRun(false);
    this->decode->start();
    connect(this->decode, SIGNAL(sendImg(QImage, int)), this, SLOT(receiveImg(QImage, int)), Qt::BlockingQueuedConnection);

    this->decode->setVideoPath(videoPath);
}

void VideoWidget::setUserid(const string &value)
{
    userid = value;
}

void VideoWidget::setCover(QString coverPath)
{
    QPixmap pixmap(coverPath);
    ui->label->setPixmap(pixmap);
//    QImage img(coverPath);
//    ui->label->setPixmap(QPixmap::fromImage(img));
//    update();
}

void VideoWidget::setCurrentFrame(int value)
{
    qDebug() << "value = " << value;
    currentFrame = value;
    ui->label_3->setText(QString::number(currentFrame));
    //设置滑块当前位置

    ui->horizontalSlider->setValue(currentFrame);
    qDebug() << " huakuai value = " << ui->horizontalSlider->value();
    this->decode->setCurrentFrame(currentFrame);
}

void VideoWidget::setTotalFrame(int value)
{
    ui->label_5->setText(QString::number(value));
    //设置滑块最大值
    qDebug() << " max value = " << value;
    ui->horizontalSlider->setMaximum(value);
    //设置滑块取值范围
    ui->horizontalSlider->setRange(0, value);
}

void VideoWidget::setDateTime(QString datetime)
{
    this->dateTIme = datetime;
}

void VideoWidget::PlayInit()
{
    ui->pushButton_3->setText("播放");
}

void VideoWidget::Sleep(int msec)
{
    //设置休眠的时间
   QTime dieTime = QTime::currentTime().addMSecs(msec);
   while(QTime::currentTime()<dieTime)
   {
       QCoreApplication::processEvents(QEventLoop::AllEvents,100);
   }
}


void VideoWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    ui->label->setPixmap(QPixmap::fromImage(this->img.rgbSwapped()));
}

void VideoWidget::receiveImg(QImage img, int currentFrame)
{
    this->img = img;
    update();
    this->currentFrame = currentFrame;
    ui->label_3->clear();
    //刷新当前帧数
    ui->label_3->setText(QString::number(currentFrame));
    //进度条更新
    ui->horizontalSlider->setValue(currentFrame);
    if(ui->horizontalSlider->value()==ui->horizontalSlider->maximum())
    {
        this->setCurrentFrame(0);
    }
}

void VideoWidget::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->text()=="播放")
    {
        this->decode->setIsRun(true);
        ui->pushButton_3->setText("暂停");
    }
    else if(ui->pushButton_3->text()=="暂停")
    {
        this->decode->setIsRun(false);
        ui->pushButton_3->setText("播放");
    }
}

void VideoWidget::on_horizontalSlider_sliderPressed()
{
    this->decode->setIsRun(false);
}

void VideoWidget::on_horizontalSlider_sliderReleased()
{
    this->decode->setCurrentFrame(ui->horizontalSlider->value());
    this->decode->setIsRun(true);
    ui->horizontalSlider->setValue(ui->horizontalSlider->value());
}

//void VideoWidget::DecodeFinish()
//{
//    this->decode->setIsRun(false);
//    this->decode->setIsStop(true);
//    this->decode->quit();
//    this->decode->wait();
//}
//显示菜单
void VideoWidget::on_pushButton_clicked()
{
    //当前视频播放到第几帧我要告诉服务器
    scheduleSvae.video_cur = this->currentFrame;
    strcpy(scheduleSvae.user_acount, this->userid.c_str());
    strcpy(scheduleSvae.video_time, this->dateTIme.toStdString().c_str());
    head.businessType = 8;
    head.businessLength = sizeof(SCHEDULE_SAVE);
    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &scheduleSvae, sizeof (SCHEDULE_SAVE));
    std::cout << "scheduleSvae.video_cur = " << scheduleSvae.video_cur;

    WriteThread::getInstance()->setData(head, bodyBuf);
    qDebug() << "-------------------------------------";
    qDebug() << "type = " << head.businessType;
    qDebug() << "----------------------------------";
    Sleep(200);
    this->decode->setIsRun(false);
    this->decode->setIsStop(true);
    //点击显示菜单时肯定关闭这个窗口且关闭当前线程
    emit this->backToMain();

}
//截图特征记录上传
void VideoWidget::on_pushButton_2_clicked()
{
    //获取当前时间
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy_MM_dd_hh_mm_ss");
    QString filename = "./Photo/" + current_date + ".jpg";
    qDebug() << "cut Photo filename = " << filename ;

    //图片保存到本地
    //红蓝色通道反转
    QImage resimg = this->img.rgbSwapped();
    resimg.save(filename);
    //发送第15个协议
    strcpy(photo.photoPath, filename.toStdString().c_str());
    strcpy(photo.photoName, QString(current_date + ".jpg").toStdString().c_str());
    //先计算文件碎片总数
    std::ifstream file(filename.toStdString().c_str(), std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        qDebug() << "Error opening file: " << filename;
        return ;
    }
    std::streampos size = file.tellg();
    qDebug () << "size = " << size ;
    if(size <=0)
        return ;
    file.close();


//    std::streampos size;
//    std::ifstream file(filename.toStdString().c_str(), std::ios::binary | std::ios::ate);
//    if (!file.is_open()) {
//        qDebug() << "Error opening file: " << filename;
//        // 检查文件是否存在
//        if (!QFile::exists(filename)) {
//            qDebug() << "File does not exist.";
//        }
//        // 检查文件权限
//        QFile f(filename);
//        if (!f.open(QIODevice::ReadOnly)) {
//            qDebug() << "Cannot open file for reading. Check permissions.";
//        }
//    } else {
//        size = file.tellg();
//        if (size == -1) {
//            qDebug() << "Error getting file size or file is empty.";
//        } else {
//            qDebug() << "size = " << size;
//        }
//        file.close();
//    }

    qDebug() << "size = " << size;
    photo.allBytes = static_cast<int>(size);

    strcpy(photo.traitPhotoTime, current_date.toStdString().c_str());
    qDebug() << "traitPhotoTime = " << photo.traitPhotoTime;
    strcpy(photo.user_account, this->userid.c_str());

    head.businessType = 15;
    head.businessLength = sizeof(PHOTO);
    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &photo, sizeof (PHOTO));
    WriteThread::getInstance()->setData(head, bodyBuf);
    qDebug() << "photo = " << photo.allBytes;

    QMessageBox::information(this, "场景重现", "截图上传成功");
    //上传图片入队
    this->splitTh->appendQueue(current_date.toStdString() + ".jpg");
    qDebug() << "queueSize = " << this->splitTh->QueueSize();



}
