#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->widget_2->close();
    ui->stackedWidget->setCurrentWidget(ui->page_6);
    this->rth = ReadThread::getInstance();
    this->wth = WriteThread::getInstance();
    this->heatrTh = HeartbeatThread::getInstance();
    this->heatrTh->start();

    //首先一进来是设置网络
    ui->widget->setStyleSheet("QWidget { border-right: 2px solid black; }");

    QFile file("./data/SetData.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //若文件中有内容，将之前配置的内容写入
    QTextStream in(&file);
    QString line[10];
    int i = 0;
    while(!in.atEnd())
    {
        line[i] = in.readLine();
        qDebug() << line[i++];
    }
    ui->lineEdit->setText(line[0]);
    ui->lineEdit_2->setText(line[1]);
    ui->lineEdit_3->setText(line[2]);
    ui->lineEdit_4->setText(line[3]);
    ui->lineEdit_5->setText(line[4]);
    ui->lineEdit_6->setText(line[5]);


    this->loginwidget = new LoginWidget;
    connect(this->loginwidget, SIGNAL(loginToMain(QString, QString)), this, SLOT(loginBackToMain(QString, QString)));
    connect(this->loginwidget, SIGNAL(loginToSet()), this, SLOT(loginToSet()));

    //视频数据列表的数据初始化
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setResizeMode(QListView::Adjust);
    ui->listWidget->setMovement(QListWidget::Static);
    //视频数据列表懒加载
    this->vScrollBar = ui->listWidget->verticalScrollBar();	//获取滚动条
    ui->listWidget->verticalScrollBar()->setStyleSheet("QScrollBar{width:40px;}");
    connect(this->vScrollBar,SIGNAL(valueChanged(int)),this,SLOT(onScrollBarValueChanged(int)));

    //视频数据列表懒加载
    this->vScrollBar2 = ui->listWidget_2->verticalScrollBar();
    ui->listWidget_2->verticalScrollBar()->setStyleSheet("QScrollBar{width:20px};");
    connect(this->vScrollBar2, SIGNAL(valueChanged(int)), this, SLOT(onScrollBarValueChanged2(int)));

    //特征图片列表懒加载
    //场景重现界面先new出来
    this->videowidget = new VideoWidget;
    connect(this->videowidget, SIGNAL(backToMain()), this, SLOT(VideoBackTOMain()));

    ui->listWidget->setStyleSheet(
                "QListWidget::item {"
                "    border: 1px solid black;"
                "    margin-bottom: 2px; /* 留出空间以显示下边框 */"
                "}"
            );

    //行车模式等需要摄像头界面的初始
    this->camdecode = CamDecode::getInstance();

    //因为是单例，而且我们在它的构造函数里都设置了先不进行视频的解码和编码
    //所以这里我们可以直接start，我们后面改set属性就可以了
    this->camdecode->setIsStop(false);
    this->camdecode->start();

    //行车模式接收解码线程传来的图片
    connect(this->camdecode, SIGNAL(sendImg(QImage)), this, SLOT(receiveImg(QImage)), Qt::BlockingQueuedConnection);
    connect(this->camdecode, SIGNAL(sendMat(Mat)), this, SLOT(receiveMat1(Mat)), Qt::BlockingQueuedConnection);
    this->timer = new QTimer(this); //创建定时器
    connect(this->timer, &QTimer::timeout, this, &MainWidget::onTimeout);   //连接信号和槽
    connect(this->camdecode, SIGNAL(TimeStart()), this, SLOT(CountTenTime()));

    this->timer2 = new QTimer(this);    //创建定时器
    connect(this->timer2, &QTimer::timeout, this, &MainWidget::onTimeout2);
    this->timer2->start(15000);


    //视频数据接收read发来的视频
    connect(this->rth, SIGNAL(emitBackPage(BACK_PAGE)), this, SLOT(showVideo(BACK_PAGE)));
    //特征记录接收read发来的图片
    connect(this->rth, SIGNAL(getPhoto(GET_PHOTOS_INFO)), this, SLOT(ShowPhoto(GET_PHOTOS_INFO)), Qt::BlockingQueuedConnection);
    //特征图片的数据初始化
    this->imgIndex = 0;
    this->videoIndex = 0;

    ui->listWidget_2->setIconSize(QSize(250,200));
    ui->listWidget_2->setViewMode(QListView::IconMode);
    ui->listWidget_2->setResizeMode(QListWidget::Adjust);
    ui->listWidget_2->setMovement(QListWidget::Static);
}

MainWidget::~MainWidget()
{
    delete ui;
}

//void MainWidget::Sleep(int msec)
//{
//    //设置休眠的时间
//    QTime dieTime = QTime::currentTime().addMSecs(msec);
//    while(QTime::currentTime()<dieTime)
//    {
//        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
//    }
//}

//行车模式
void MainWidget::on_pushButton_3_clicked()
{
    if(ui->label->text()=="未登录用户")
    {
        QMessageBox::warning(this, "设置界面", "请先登录");
        return ;
    }

    if(this->camdecode->getIsRun()&&this->camdecode->getIsRecord())
    {
        this->camdecode->swapWindow();
    }

    //此时可能在进行其他模式，先都关掉，打开新的视频（切换摄像头）后再开始线程
    this->camdecode->setIsRun(false);
    this->camdecode->setIsRecord(false);
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    //开启解码线程
//    this->camdecode->setVideoPath("./Video/car02.mp4");
    this->camdecode->setFlag(1);
    this->camdecode->setIsRun(true);
    this->camdecode->setIsRecord(true);
}
//去倒车模式
void MainWidget::on_pushButton_4_clicked()
{
    if(ui->label->text()=="未登录用户")
    {
        QMessageBox::warning(this, "设置界面", "请先登录");
        return ;
    }

    if(this->camdecode->getIsRun()&&this->camdecode->getIsRecord())
    {
        this->camdecode->swapWindow();
    }

    //此时可能在进行其他模式，先都关掉，打开新的视频（切换摄像头）后再开始线程
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    this->camdecode->setIsRun(false);
    this->camdecode->setIsRecord(false);
    //隐藏左侧菜单栏
    ui->widget->hide();
    ui->stackedWidget->setGeometry(0,0,1200,700);
    ui->label_5->setGeometry(100,90,1000,551);
    //选择倒车模式
//    this->camdecode->setVideoPath("./Video/carport1.mp4");
//    this->camdecode->setVideoPath("0");

    this->camdecode->setFlag(2);
    //重新设置让线程继续跑
    this->camdecode->setIsRun(true);
    this->camdecode->setIsRecord(true);
}
//视频记录
void MainWidget::on_pushButton_2_clicked()
{
    if(ui->label->text()=="未登录用户")
    {
        QMessageBox::warning(this, "设置界面", "请先登录");
        return ;
    }
    if(this->camdecode->getIsRun()&&this->camdecode->getIsRecord())
    {
        this->camdecode->swapWindow();
    }

    ui->stackedWidget->setCurrentIndex(0);
    //此时可能在进行其他模式，先都关掉
    this->camdecode->setIsRun(false);
    this->camdecode->setIsRecord(false);

    ui->listWidget->clear();
    //查询视频
    this->videoSearch.page = 0;
    this->videoIndex = 0;
    strcpy(this->videoSearch.user_acount, this->userid.c_str());
    head.businessType = 6;
    head.businessLength = sizeof(TURN_PAGE);
    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &videoSearch, sizeof (TURN_PAGE));
    this->wth->setData(head, bodyBuf);
}

void MainWidget::VideoBackTOMain()
{
    this->videowidget->close();
//    connect(this->videowidget, SIGNAL(backToMain()), this, SLOT(VideoBackTOMain()));
    //窗口都离开了，那这个线程确实要结束了，setIsStop
    ui->listWidget->clear();
    //查询视频
    this->videoSearch.page = 0;
    this->videoIndex = 0;
    strcpy(this->videoSearch.user_acount, this->userid.c_str());
    head.businessType = 6;
    head.businessLength = sizeof(TURN_PAGE);
    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &videoSearch, sizeof (TURN_PAGE));
    this->wth->setData(head, bodyBuf);
    this->show();
}

void MainWidget::receiveImg(QImage img)
{
    this->img = img;
    update();
}

void MainWidget::receiveMat1(Mat mat)
{
    this->mat1 = mat;
    if((this->mat1.cols>0)&&(this->mat2.cols>0))
    {
        update();
    }

}

void MainWidget::receiveMat2(Mat mat)
{
    this->mat2 = mat;
}

//read线程读完后显示特征记录图片
void MainWidget::ShowPhoto(GET_PHOTOS_INFO photoInfo)
{
    //如果flag==-1，这个时候用户没有任何图片信息
//    if(photoInfo.allPhoto/(this->imgIndex+1)*9 <= 1)
//    {
//        QMessageBox::warning(this, "特征图片", "当前没有特征图片记录");
//        return ;
//    }

    if(photoInfo.flag == 0)
    {
        QMessageBox::warning(this, "特征图片", "当前没有特征图片记录");
        return ;
    }

    cout << "allphoto = " << sizeof(photoInfo.photoArr)/sizeof(photoInfo.photoArr[0]) << endl;
    for (int i= 0;i< photoInfo.flag ;i++)
    {
        this->listwidgetItem = new QListWidgetItem(QIcon(photoInfo.photoArr[i].photoPath), QString(photoInfo.photoArr[i].traitPhotoTime));
        this->listwidgetItem->setSizeHint(QSize(250,200));
        //存入这个图片的文件日期
        this->listwidgetItem->setData(Qt::UserRole, QString(photoInfo.photoArr[i].traitPhotoTime));
        ui->listWidget_2->addItem(this->listwidgetItem);
    }
}

void MainWidget::showVideo(BACK_PAGE backPage)
{
    //如果flag==-1，这个时候用户没有任何视频信息
    qDebug() << "backPage.count = " << backPage.video_count ;
    qDebug() << "flag = " << backPage.flag ;
    if(backPage.video_count == 0)
    {
        QMessageBox::warning(this, "视频记录", "当前没有视频记录");
        return ;
    }
    //否则就是有视频记录
    for (int i=0;i < backPage.flag;i++)
    {
        //视频封面、日期、进度
        QListWidgetItem *item1 = new QListWidgetItem;
        //进度百分比

        int scheduleNum = (100 *backPage.videoArr[i].video_cur)/backPage.videoArr[i].video_num;
//        qDebug() << "---------------------------------------------------------------";
//        qDebug() << "Main cur = " << backPage.videoArr[i].video_cur << "%";
//        qDebug() << "Main total = " << backPage.videoArr[i].video_num << "%";
//        qDebug() << "Main scheduleNum = " << scheduleNum << "%";
//        qDebug() << "---------------------------------------------------------------";
//        qDebug() << "main " << backPage.videoArr[i].video_cover;
//        qDebug() << "QString main " << QString(backPage.videoArr[i].video_cover);
        VideoListItem * videoItem1 = new VideoListItem(QString(backPage.videoArr[i].video_time), QString("进度%1%").arg(QString::number(scheduleNum)), QPixmap(QString(backPage.videoArr[i].video_cover)));
        item1->setSizeHint(QSize(350,200));
        //存入这个视频的播放路径
        item1->setData(Qt::UserRole, QString(backPage.videoArr[i].video_path));
        //当存放前帧数
        item1->setData(Qt::UserRole+1, backPage.videoArr[i].video_cur);
        qDebug() << "Main cur = " << backPage.videoArr[i].video_cur ;
        //总帧数
        item1->setData(Qt::UserRole+2, backPage.videoArr[i].video_num);
        //时间
        item1->setData(Qt::UserRole+3, QString(backPage.videoArr[i].video_time));
        //封面
        item1->setData(Qt::UserRole+4, QString(backPage.videoArr[i].video_cover));
        qDebug() << "main" << item1->data(Qt::UserRole).toString();
        ui->listWidget->addItem(item1);
        ui->listWidget->setItemWidget(item1, videoItem1);
    }
}

void MainWidget::onScrollBarValueChanged(int value)
{
    if(value == this->vScrollBar->maximum())//滚动条拉到低时触发
    {
        //查询视频
        this->videoIndex = ui->listWidget->count()/6 ;
        this->videoSearch.page = this->videoIndex + (ui->listWidget->count() %6==0?0:1);

        qDebug() << "page = " << ui->listWidget->count();
        strcpy(this->videoSearch.user_acount, this->userid.c_str());
        head.businessType = 6;
        head.businessLength = sizeof(TURN_PAGE);
        char bodyBuf[2000] = {0};
        memcpy(bodyBuf, &videoSearch, sizeof (TURN_PAGE));
        this->wth->setData(head, bodyBuf);

//        for (int i=1;i<=6;i++)
//        {
//            QListWidgetItem *item1 = new QListWidgetItem;
//            VideoListItem * videoItem1 = new VideoListItem(QString("Video%1").arg(i), QString("%2").arg(i), QPixmap("./img/qt.jpg"));
//            item1->setSizeHint(QSize(350,180));
//            ui->listWidget->addItem(item1);
//            ui->listWidget->setItemWidget(item1, videoItem1);

//        }
    }
}

void MainWidget::onScrollBarValueChanged2(int value)
{
    if(value == this->vScrollBar->maximum())//滚动条拉到低时触发
    {
        //图片查询的业务类型
        head.businessType = 16;
        head.businessLength = sizeof (TURN_PICTURE);
        pictrue.page = this->imgIndex;
        qDebug() << "count = " << ui->listWidget_2->count();
        this->imgIndex = ui->listWidget_2->count()/9;
        strcpy(pictrue.user_acount, this->userid.c_str());
        char bodyBuf[2000] = {0};
        memcpy(bodyBuf, &pictrue, sizeof (TURN_PICTURE));
        this->wth->setData(head, bodyBuf);
    }
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    //根据不同当前下标进行判断，选择每个窗口对应的label进行视频的播放
    //判断当前page是行车模式
    if(ui->stackedWidget->currentIndex()==1)
    {
        ui->label_3->setPixmap(QPixmap::fromImage(this->img.rgbSwapped()));
    }
    //判断当前如果是倒车模式
    else if (ui->stackedWidget->currentIndex()==2)
    {
        ui->label_5->setPixmap(QPixmap::fromImage(this->img.rgbSwapped()));
    }
    //3
    else if (ui->stackedWidget->currentIndex()==3)
    {
        this->img2 = QImage(mat1.data, mat1.cols, mat1.rows, mat1.cols*mat1.channels(), QImage::Format_RGB888);
        this->img = QImage(mat2.data, mat2.cols, mat2.rows, mat2.cols*mat1.channels(), QImage::Format_RGB888);
        ui->label_2->setPixmap(QPixmap::fromImage(this->img.rgbSwapped()));
        ui->label_16->setPixmap(QPixmap::fromImage(this->img2.rgbSwapped()));
    }
}

void MainWidget::onTimeout()
{
    qDebug() << "定时器触发，已经过了30秒";
    //重新启动录制
    this->camdecode->setIsRecord(true);
}

void MainWidget::onTimeout2()
{
    if(this->camdecode->getIsRun() == true)
        this->camdecode->autoPhoto();
}

void MainWidget::CountTenTime()
{
    this->timer->start(10000);
}


//特征记录是page5
void MainWidget::on_pushButton_6_clicked()
{
    if(ui->label->text()=="未登录用户")
    {
        QMessageBox::warning(this, "设置界面", "请先登录");
        return ;
    }

    if(this->camdecode->getIsRun()&&this->camdecode->getIsRecord())
    {
        this->camdecode->swapWindow();
    }
    //此时可能在进行其他模式，先都关掉，打开新的视频（切换摄像头）后再开始线程
    this->camdecode->setIsRun(false);
    this->camdecode->setIsRecord(false);

    ui->stackedWidget->setCurrentWidget(ui->page_5);
    //图片列表
    ui->listWidget_2->clear();
    //图片查询的业务类型
    head.businessType = 16;
    head.businessLength = sizeof (TURN_PICTURE);
    pictrue.page = this->imgIndex;
    strcpy(pictrue.user_acount, this->userid.c_str());
    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &pictrue, sizeof (TURN_PICTURE));
    this->wth->setData(head, bodyBuf);

    //假数据
//    this->listwidgetItem = new QListWidgetItem(QIcon("./Photo/2024_09_05_01_04_03.jpg"), QString("2024_09_05_01_04_03"));
//    this->listwidgetItem->setSizeHint(QSize(250,200));
//    this->listwidgetItem->setData(Qt::UserRole, QString("2024_09_05_01_04_03"));
//    ui->listWidget_2->addItem(this->listwidgetItem);
}

//显示菜单
void MainWidget::on_pushButton_8_clicked()
{
    ui->stackedWidget->setGeometry(350,0,831,700);
    ui->label_5->setGeometry(20,90,800,551);
    ui->widget->show();
}

void MainWidget::setFail()
{
    QMessageBox::warning(this, "系统配置", "请重新连接网络");
//    this->close();

}

void MainWidget::setSuccess()
{
    QMessageBox::information(this, "设置界面", "设置保存成功");
   this->hide();
    this->loginwidget->show();
}

void MainWidget::loginToSet()
{
    this->loginwidget->close();
    this->loginwidget->Clear();
    this->close();
}

void MainWidget::loginBackToMain(QString userid, QString username)
{
    this->loginwidget->close();
    this->show();
    this->heatrTh->setIsRun(true);
    //userid用于告诉服务器登录的用户是谁
    this->userid = userid.toStdString();
    ui->label->setText(username + "用户");
    //摄像头线程需要知道此时是哪个用户
    this->camdecode->setUserid(this->userid);
    this->videowidget->setUserid(this->userid);
    //切换到视频数据列表界面
    ui->stackedWidget->setCurrentWidget(ui->page);
    //查询视频
    this->videoSearch.page = 0;
    strcpy(this->videoSearch.user_acount, this->userid.c_str());
    head.businessType = 6;
    head.businessLength = sizeof(TURN_PAGE);
    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &videoSearch, sizeof (TURN_PAGE));
    this->wth->setData(head, bodyBuf);
}
//双击放大查看特征图片
void MainWidget::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
    ui->widget_2->show();
    //拼合出图片路径
    ui->label_4->setPixmap(QPixmap(QString("./Photo/" + item->data(Qt::UserRole).toString() + ".jpg")));
    ui->label_6->setText(item->data(Qt::UserRole).toString());
}

void MainWidget::on_pushButton_9_clicked()
{
    ui->widget_2->close();
}
//场景重现界面
void MainWidget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    this->videowidget->setVideoPath(item->data(Qt::UserRole).toString());
    qDebug() << "video " << item->data(Qt::UserRole).toString();
    //场景重现界面显示封面
    this->videowidget->setCover(item->data(Qt::UserRole+4).toString());
    qDebug() << "-------------------------------------------------";
    qDebug() << "Cover = " << item->data(Qt::UserRole+4).toString();
    qDebug() << "-------------------------------------------------";

    //视频总帧数
    this->videowidget->setTotalFrame(item->data(Qt::UserRole+2).toInt());
    //设置视频当前帧
    this->videowidget->setCurrentFrame(item->data(Qt::UserRole+1).toInt());
    qDebug() <<"current = " << item->data(Qt::UserRole+1).toInt();

    //视频时间
    this->videowidget->setDateTime(item->data(Qt::UserRole+3).toString());

    this->videowidget->PlayInit();
    this->videowidget->show();
    this->hide();
}
//配置网络槽函数
void MainWidget::on_pushButton_10_clicked()
{
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()
          ||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()
          ||ui->lineEdit_5->text().isEmpty()||ui->lineEdit_6->text().isEmpty())
    {
        QMessageBox::warning(this, "设置界面", "设置内容填写不完整");
        return ;
    }
    //获取IP
    QString IP = ui->lineEdit->text() + "." + ui->lineEdit_2->text() + "." \
                +ui->lineEdit_3->text() + "." + ui->lineEdit_4->text();
    qDebug() << "IP = " << IP;

    //获取端口
    QString port = ui->lineEdit_5->text();
    qDebug() << "port = " << port;
    //获取设置大小
    QString size = ui->lineEdit_6->text();

    this->sc = SocketConnect::getInstance();
    //配置读写socketfd
    this->wth = WriteThread::getInstance();
    this->rth = ReadThread::getInstance();
    this->wth->setWfd(this->sc->getSocketfd());
    this->rth->setRfd(this->sc->getSocketfd());

    this->wth->start();
    this->rth->start();
    this->splitTh = SplitFile::getInstance();
    this->splitTh->start();

    connect(this->rth, SIGNAL(setFail()), this, SLOT(setFail()));
    connect(this->sc, SIGNAL(setSuccess()), this, SLOT(setSuccess()), Qt::QueuedConnection);


    this->sc->Socketinet(IP, port);



    //配置信息写入文件
    QFile file("./data/SetData.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "无法打开SetData.txt文件" ;
        return ;
    }
    QTextStream out(&file);
    out << ui->lineEdit->text() << endl;
    out << ui->lineEdit_2->text() << endl;
    out << ui->lineEdit_3->text() << endl;
    out << ui->lineEdit_4->text() << endl;
    out << ui->lineEdit_5->text() << endl;
    out << ui->lineEdit_6->text() << endl;
    file.close();

//    QMessageBox::information(this, "设置界面", "设置保存成功");
//    this->close();
//    this->loginwidget->show();
}

void MainWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    //此时如果有在录制视频。视频录制了多少就发给服务器
    if(this->camdecode->getIsRecord())
    {
        //摄像头把此时录制的视频的信息发给服务器，然后摄像头线程也要关闭
        this->camdecode->MainClose();
    }
}
//鸟瞰模式
void MainWidget::on_pushButton_5_clicked()
{
    if(ui->label->text()=="未登录用户")
    {
        QMessageBox::warning(this, "设置界面", "请先登录");
        return ;
    }

    if(this->camdecode->getIsRun()&&this->camdecode->getIsRecord())
    {
        this->camdecode->swapWindow();
    }

    this->decode = new Decode;
    this->decode->setVideoPath("./Video/niaokan.mp4");
    this->decode->setFlag(2);
    connect(this->decode, SIGNAL(sendMat(Mat)), this, SLOT(receiveMat2(Mat)), Qt::BlockingQueuedConnection);

    //此时可能在进行其他模式，先都关掉
    this->camdecode->setIsRun(false);
    this->camdecode->setIsRecord(false);
    ui->stackedWidget->setCurrentWidget(ui->page_4);
//    this->camdecode->setVideoPath("./Video/car02.mp4");
    this->camdecode->setFlag(3);
    //重新设置让线程继续跑
    this->camdecode->setIsRun(true);
    this->decode->setIsRun(true);
    this->decode->setIsStop(false);
    this->decode->start();
    this->camdecode->setIsRecord(true);

}

void MainWidget::on_pushButton_7_clicked()
{
    if(this->camdecode->getIsRun()&&this->camdecode->getIsRecord())
    {
        this->camdecode->swapWindow();
    }

    //此时可能在进行其他模式，先都关掉
    this->camdecode->setIsRun(false);
    this->camdecode->setIsRecord(false);

    ui->stackedWidget->setCurrentWidget(ui->page_6);
}

void MainWidget::on_pushButton_clicked()
{

    if(this->camdecode->getIsRun()&&this->camdecode->getIsRecord())
    {
        this->camdecode->swapWindow();
    }

    //此时可能在进行其他模式，先都关掉
    this->camdecode->setIsRun(false);
    this->camdecode->setIsRecord(false);

    ui->label->setText("未登录用户");
    this->hide();
    this->loginwidget->show();
//    ui->stackedWidget->setCurrentWidget(ui->page_6);

}
