#include "camdecode.h"

CamDecode* CamDecode::camth = nullptr;

CamDecode* CamDecode::getInstance()
{
    if(CamDecode::camth == nullptr)
    {
        CamDecode::camth = new CamDecode;
    }
    return CamDecode::camth;
}

bool CamDecode::getIsRun() const
{
    return isRun;
}

void CamDecode::setIsRun(bool value)
{
    isRun = value;
}

bool CamDecode::getIsStop() const
{
    return isStop;
}

void CamDecode::setIsStop(bool value)
{
    isStop = value;
}

int CamDecode::processImgR(Mat src)
{
    Mat tmp;

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    vector<Point> hull;

    CvPoint2D32f tempNode;
    CvMemStorage* storage = cvCreateMemStorage();
    CvSeq* pointSeq = cvCreateSeq(CV_32FC2, sizeof(CvSeq), sizeof(CvPoint2D32f), storage);

    Rect* trackBox;
    Rect* result;
    int resultNum = 0;

    int area = 0;
    src.copyTo(tmp);
    //提取轮廓
    findContours(tmp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0)
    {
        trackBox = new Rect[contours.size()];
        result = new Rect[contours.size()];

        //确定要跟踪的区域
        for (int i = 0; i < contours.size(); i++)
        {
            cvClearSeq(pointSeq);
            // 获取凸包的点集
            convexHull(Mat(contours[i]), hull, true);
            int hullcount = (int)hull.size();
            // 凸包的保存点
            for (int j = 0; j < hullcount - 1; j++)
            {
                tempNode.x = hull[j].x;
                tempNode.y = hull[j].y;
                cvSeqPush(pointSeq, &tempNode);
            }

            trackBox[i] = cvBoundingRect(pointSeq);
        }

        if (isFirstDetectedR)
        {
            lastTrackBoxR = new Rect[contours.size()];
            for (int i = 0; i < contours.size(); i++)
                lastTrackBoxR[i] = trackBox[i];
            lastTrackNumR = contours.size();
            isFirstDetectedR = false;
        }
        else
        {
            for (int i = 0; i < contours.size(); i++)
            {
                for (int j = 0; j < lastTrackNumR; j++)
                {
                    if (isIntersected(trackBox[i], lastTrackBoxR[j]))
                    {
                        result[resultNum] = trackBox[i];
                        break;
                    }
                }
                resultNum++;
            }
            delete[] lastTrackBoxR;
            lastTrackBoxR = new Rect[contours.size()];
            for (int i = 0; i < contours.size(); i++)
            {
                lastTrackBoxR[i] = trackBox[i];
            }
            lastTrackNumR = contours.size();
        }

        delete[] trackBox;
    }
    else
    {
        isFirstDetectedR = true;
        result = NULL;
    }
    cvReleaseMemStorage(&storage);

    if (result != NULL)
    {
        for (int i = 0; i < resultNum; i++)
        {
            area += result[i].area();
        }
    }
    delete[] result;

    return area;
}

int CamDecode::processImgG(Mat src)
{
    Mat tmp;

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    vector< Point > hull;

    CvPoint2D32f tempNode;
    CvMemStorage* storage = cvCreateMemStorage();
    CvSeq* pointSeq = cvCreateSeq(CV_32FC2, sizeof(CvSeq), sizeof(CvPoint2D32f), storage);

    Rect* trackBox;
    Rect* result;
    int resultNum = 0;

    int area = 0;

    src.copyTo(tmp);
    // Extract the contour
    findContours(tmp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0)
    {
        trackBox = new Rect[contours.size()];
        result = new Rect[contours.size()];

        // Determine the area to track
        for (int i = 0; i < contours.size(); i++)
        {
            cvClearSeq(pointSeq);
            // Get the point set of the convex hull
            convexHull(Mat(contours[i]), hull, true);
            int hullcount = (int)hull.size();
            // Save points of the convex hull
            for (int j = 0; j < hullcount - 1; j++)
            {
                //line(showImg, hull[j + 1], hull[j], Scalar(255, 0, 0), 2, CV_AA);
                tempNode.x = hull[j].x;
                tempNode.y = hull[j].y;
                cvSeqPush(pointSeq, &tempNode);
            }

            trackBox[i] = cvBoundingRect(pointSeq);
        }

        if (isFirstDetectedG)
        {
            lastTrackBoxG = new Rect[contours.size()];
            for (int i = 0; i < contours.size(); i++)
                lastTrackBoxG[i] = trackBox[i];
            lastTrackNumG = contours.size();
            isFirstDetectedG = false;
        }
        else
        {
            for (int i = 0; i < contours.size(); i++)
            {
                for (int j = 0; j < lastTrackNumG; j++)
                {
                    if (isIntersected(trackBox[i], lastTrackBoxG[j]))
                    {
                        result[resultNum] = trackBox[i];
                        break;
                    }
                }
                resultNum++;
            }
            delete[] lastTrackBoxG;
            lastTrackBoxG = new Rect[contours.size()];
            for (int i = 0; i < contours.size(); i++)
            {
                lastTrackBoxG[i] = trackBox[i];
            }
            lastTrackNumG = contours.size();
        }

        delete[] trackBox;
    }
    else
    {
        isFirstDetectedG = true;
        result = NULL;
    }
    cvReleaseMemStorage(&storage);

    if (result != NULL)
    {
        for (int i = 0; i < resultNum; i++)
        {
            area += result[i].area();
        }
    }
    delete[] result;

    return area;
}
//确定两个矩形区域是否相交
bool CamDecode::isIntersected(Rect r1, Rect r2)
{
    int minX = max(r1.x, r2.x);
    int minY = max(r1.y, r2.y);
    int maxX = min(r1.x + r1.width, r2.x + r2.width);
    int maxY = min(r1.y + r1.height, r2.y + r2.height);

    if (minX < maxX && minY < maxY)
        return true;
    else
        return false;
}

void CamDecode::lightDetect(Mat &frame)
{
    int redCount = 0;
    int greenCount = 0;

    Mat img;
    Mat imgYCrCb;
    Mat imgGreen;
    Mat imgRed;

    // 亮度参数
    double a = 0.3; // gain, modify this only.
    double b = (1 - a) * 125; // bias

    //调整亮度
    frame.convertTo(img, img.type(), a, b);

    //转换为YCrCb颜色空间
    cvtColor(img, imgYCrCb, CV_BGR2YCrCb);

    imgRed.create(imgYCrCb.rows, imgYCrCb.cols, CV_8UC1);
    imgGreen.create(imgYCrCb.rows, imgYCrCb.cols, CV_8UC1);

    //分解YCrCb的三个成分
    vector<Mat> planes;
    split(imgYCrCb, planes);
    // 遍历以根据Cr分量拆分红色和绿色
    MatIterator_<uchar> it_Cr = planes[1].begin<uchar>(),
                        it_Cr_end = planes[1].end<uchar>();
    MatIterator_<uchar> it_Red = imgRed.begin<uchar>();
    MatIterator_<uchar> it_Green = imgGreen.begin<uchar>();

    for (; it_Cr != it_Cr_end; ++it_Cr, ++it_Red, ++it_Green)
    {
        // RED, 145<Cr<470
        if (*it_Cr > 145 && *it_Cr < 470)
            *it_Red = 255;
        else
            *it_Red = 0;

        // GREEN 95<Cr<110
        if (*it_Cr > 95 && *it_Cr < 110)
            *it_Green = 255;
        else
            *it_Green = 0;
    }

    //膨胀和腐蚀
    dilate(imgRed, imgRed, Mat(15, 15, CV_8UC1), Point(-1, -1));
    erode(imgRed, imgRed, Mat(1, 1, CV_8UC1), Point(-1, -1));
    dilate(imgGreen, imgGreen, Mat(15, 15, CV_8UC1), Point(-1, -1));
    erode(imgGreen, imgGreen, Mat(1, 1, CV_8UC1), Point(-1, -1));

    redCount = processImgR(imgRed);
    greenCount = processImgG(imgGreen);
//    cout << "red:" << redCount << ";  " << "green:" << greenCount << endl;

    if(redCount == 0 && greenCount == 0)
    {
        cv::putText(frame, "NULL", Point(200, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2, 8, 0);
    }else if(redCount > greenCount)
    {
        cv::putText(frame, "red", Point(200, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 0, 255), 2, 8, 0);
    }else{
        cv::putText(frame, "green", Point(200, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 0), 2, 8, 0);
    }

//        imshow("video", frame);

//        imshow("Origin", frame);
//        imshow("Red", imgRed);
//        imshow("Green", imgGreen);

//        // Handle with the keyboard input
//        if (cvWaitKey(20) == 'q')
    //            break;
}
//倒车距离检测函数
void CamDecode::ObstacleRanging(Mat &frame)
{
    Mat grayImage;
    Mat binaryImage;
    Mat reverseBinaryImage;
    Mat imgROI;
    Mat drawing;
    int delay = 10;

    /****ROI****/
    if (!a)
    {
//        cout << "图像的宽度：" << frame.size().width << ",图像的高度：" << frame.size().height << endl;
        a = true;
    }

    Mat mask = Mat::zeros(frame.size().height, frame.size().width, CV_8UC1);    //八位单通道
     //梯形ROI
    //vector(向量): C++中的一种数据结构,确切的说是一个类.它相当于一个动态的数组  相当于存放点的坐标的容器
    vector<vector<Point>> contour;  //vector<vector<Point>>。外层vector的size代表了图像中轮廓的个数，里面vector的size代表了轮廓上点的个数。
    vector<Point> pts;
    pts.push_back(Point(140,400));
    pts.push_back(Point(400, 400));
    pts.push_back(Point(540, 700));
    pts.push_back(Point(0, 700));
    //push_back   在数组的最后添加一个数据  即将四个坐标点依次存入数组
    contour.push_back(pts);
    drawContours(mask, contour, 0, Scalar::all(255), -1);
    frame.copyTo(imgROI, mask); // 将 frame 的位于 mask 中的部分，拷贝到 imgROI 中。

    //为倒车的辅助线进行坐标的设置
//    vector<vector<Point>> contour2;
//    vector<Point> pts2;
//    contour2.push_back(pts2);
//    // 绘制第一条绿线
//    pts2.push_back(Point(180,400)); //0
//    pts2.push_back(Point(220, 400));    //1
//    pts2.push_back(Point(320,400));     //2
//    pts2.push_back(Point(360, 400));    //3
//    // 第二条浅黄色线
//    pts2.push_back(Point(160,480));     //4
//    pts2.push_back(Point(200, 480));    //5
//    pts2.push_back(Point(340,480));     //6
//    pts2.push_back(Point(380, 480));    //7
//    pts2.push_back(Point(120,640));     //8
//    pts2.push_back(Point(160, 640));    //9
//    pts2.push_back(Point(380,640));     //10
//    pts2.push_back(Point(420, 640));    //11
//    //第三条红线
//    pts2.push_back(Point(80,800));      //12
//    pts2.push_back(Point(120, 800));    //13
//    pts2.push_back(Point(420,800));     //14
//    pts2.push_back(Point(460, 800));    //15

//    pts2.push_back(Point(40,960));      //16
//    pts2.push_back(Point(500,960));     //17
//    pts2.push_back(Point(100,720));      //18
//    pts2.push_back(Point(440,720));      //19


//    //绘制边框
//    drawContours(frame, contour, 0, Scalar(255), -1);
//    Scalar color = Scalar(0,255,0);
//    int thickness = 10; //线条宽度
//    // 绘制第一条绿线
//    line(frame, pts2[0], pts2[1], color, thickness);
//    line(frame, pts2[2], pts2[3], color, thickness);

//    // 第二条浅黄色线
//    line(frame, pts2[4], pts2[5], Scalar(51,255,255), thickness);
//    line(frame, pts2[6], pts2[7], Scalar(51,255,255), thickness);

//    line(frame, pts2[8], pts2[9], Scalar(51,255,255), thickness);
//    line(frame, pts2[10], pts2[11], Scalar(51,255,255), thickness);
//    //第三条红线
//    line(frame, pts2[12], pts2[13], Scalar(0,0,255), thickness);
//    line(frame, pts2[14], pts2[15], Scalar(0,0,255), thickness);

//    //梯形两个腰的绘制
//    line(frame, pts2[0], pts2[4], Scalar(0,255,0), thickness);
//    line(frame, pts2[3], pts2[7], Scalar(0,255,0), thickness);

//    line(frame, pts2[4], pts2[8], Scalar(51,255,255), thickness);
//    line(frame, pts2[7], pts2[11], Scalar(51,255,255), thickness);

//    line(frame, pts2[16], pts2[12], Scalar(0,0,255), thickness);
//    line(frame, pts2[15], pts2[17], Scalar(0,0,255), thickness);

//    line(frame, pts2[18], pts2[8], Scalar(51,255,255), thickness);
//    line(frame, pts2[19], pts2[11], Scalar(51,255,255), thickness);

//    line(frame, pts2[18], pts2[12], Scalar(0,0,255), thickness);
//    line(frame, pts2[19], pts2[15], Scalar(0,0,255), thickness);









    //为倒车的辅助线进行坐标的设置
    vector<vector<Point>> contour2;
    vector<Point> pts2;
    contour2.push_back(pts2);
    // 绘制第一条绿线
    pts2.push_back(Point(180,280));     //0
    pts2.push_back(Point(220, 280));    //1
    pts2.push_back(Point(390,280));     //2
    pts2.push_back(Point(430, 280));    //3
    // 第二条浅黄色线
    pts2.push_back(Point(160,310));     //4
    pts2.push_back(Point(200, 310));    //5
    pts2.push_back(Point(410,310));     //6
    pts2.push_back(Point(450, 310));    //7

    pts2.push_back(Point(120,370));     //8
    pts2.push_back(Point(160, 370));    //9
    pts2.push_back(Point(450,370));     //10
    pts2.push_back(Point(490, 370));    //11
    //第三条红线
    pts2.push_back(Point(80,430));      //12
    pts2.push_back(Point(120, 430));    //13
    pts2.push_back(Point(490,430));     //14
    pts2.push_back(Point(530,430));    //15

    pts2.push_back(Point(40,490));      //16
    pts2.push_back(Point(570,490));     //17
    pts2.push_back(Point(100,400));      //18
    pts2.push_back(Point(510,400));      //19  150


//    绘制边框
//    drawContours(frame, contour, 0, Scalar(255), -1);
    Scalar color = Scalar(0,255,0);
    int thickness = 10; //线条宽度
    // 绘制第一条绿线
    line(frame, pts2[0], pts2[1], color, thickness);
    line(frame, pts2[2], pts2[3], color, thickness);

    // 第二条浅黄色线
    line(frame, pts2[4], pts2[5], Scalar(51,255,255), thickness);
    line(frame, pts2[6], pts2[7], Scalar(51,255,255), thickness);

    line(frame, pts2[8], pts2[9], Scalar(51,255,255), thickness);
    line(frame, pts2[10], pts2[11], Scalar(51,255,255), thickness);
    //第三条红线
    line(frame, pts2[12], pts2[13], Scalar(0,0,255), thickness);
    line(frame, pts2[14], pts2[15], Scalar(0,0,255), thickness);

    //梯形两个腰的绘制
    line(frame, pts2[0], pts2[4], Scalar(0,255,0), thickness);
    line(frame, pts2[3], pts2[7], Scalar(0,255,0), thickness);

    line(frame, pts2[4], pts2[8], Scalar(51,255,255), thickness);
    line(frame, pts2[7], pts2[11], Scalar(51,255,255), thickness);

    line(frame, pts2[16], pts2[12], Scalar(0,0,255), thickness);
    line(frame, pts2[15], pts2[17], Scalar(0,0,255), thickness);

    line(frame, pts2[18], pts2[8], Scalar(51,255,255), thickness);
    line(frame, pts2[19], pts2[11], Scalar(51,255,255), thickness);

    line(frame, pts2[18], pts2[12], Scalar(0,0,255), thickness);
    line(frame, pts2[19], pts2[15], Scalar(0,0,255), thickness);

    //去噪
    //blur(imgROI,grayImage,Size(3, 3));
    medianBlur(imgROI, grayImage, 3);

    //灰度处理
    cvtColor(grayImage, grayImage, CV_BGR2GRAY);

    threshold(grayImage, binaryImage, 90, 255, CV_THRESH_BINARY); //转换为二值图
    //imshow("threshold", binaryImage);
    //开运算和形态学梯度

    Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
    morphologyEx(binaryImage, binaryImage, MORPH_OPEN, element);

    Mat element1 = getStructuringElement(MORPH_RECT, Size(2, 2));
    morphologyEx(binaryImage, binaryImage, MORPH_GRADIENT, element1);
    //namedWindow("预处理");
    //imshow("morphologyEx", binaryImage);
    /*轮廓提取*/
    vector< vector< Point> > contours;
    findContours(binaryImage, contours, CV_RETR_EXTERNAL, CV_RETR_TREE);
    vector<vector<Point> >::iterator itc = contours.begin();
    while (itc != contours.end())
    {
        if (itc->size() < 100)
        {
            itc = contours.erase(itc);  //删除轮廓
        }
        else
        {
            ++itc;
        }
    }
    drawContours(binaryImage, contours, -1, Scalar(255), 1);
    //计算轮廓的面积
    for (int i = 0; i < (int)contours.size(); i++)
    {
        double g_dConArea = contourArea(contours[i], false);

//        cout << "【无障碍区域轮廓的面积为：】" << g_dConArea << endl;
        if (g_dConArea < 100000)//报警
        {
            double distance;
            distance = g_dConArea / 10000;
            //printf("%f,%f,%f\n", distance);
            char buf[100];
            printf("离前车距离：");
            printf("%f\2", distance);
            printf("米");
            //printf(buf,"%f,%f,%f\n", distance);
            if(distance < 1.5)
            {
                //写字
                //putText(frame,"waring",Point(100,100),FONT_HERSHEY_SIMPLEX,2,Scalar(0,0,255),4,8);
                //imshow("frame",frame);
                //MessageBeep(MB_OK);
                cout << "\n前方有障碍物！\n" << endl;
//                QMessageBox::warning(0, "车距过近，请注意安全！", "车距预警");
                cv::putText(frame, "WARNING", Point(200, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 0, 255), 2, 8, 0);
                //MessageBox(0, TEXT("离前车距离："),  buf, MB_OK);
            }
        }

    }
}

void CamDecode::detecCarRaw(Mat &frame, double scale)
{
    //1.灰度处理
        Mat gray;
        cvtColor(frame, gray, CV_BGR2GRAY);
        //2.将灰度处理的结果图缩小到原来的一半
        //opencv是先写高度再写宽度
        Mat smalling(cvRound(frame.rows/scale), cvRound(frame.cols/scale), CV_8UC1);
        resize(gray, smalling, smalling.size(), 0, 0, INTER_LINEAR);
        //3.直方图均衡化
        equalizeHist(smalling, smalling);
        //4.用训练好的级联分类器模型进行识别车辆
        vector<Rect>cars;
        //扫面过程
        cascade.detectMultiScale(smalling, cars, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30,30));
        //5.绘制边框
        vector<Rect>::const_iterator iter;
        for (iter = cars.begin(); iter!=cars.end();iter++) {
            rectangle(frame, cvPoint(cvRound(iter->x*scale), cvRound(iter->y*scale)),
                             cvPoint(cvRound((iter->x+iter->width)*scale), cvRound((iter->y+iter->height)*scale)),
                             Scalar(255,0,0),
                             2,8);
        }
}

void CamDecode::setVideoPath(QString filename)
{
    if(filename == "0")
    {
        this->cap->open(0);
    }
    else
    {
        this->cap->open(filename.toStdString());
    }

    msleep(100);
}

void CamDecode::autoPhoto()
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

    msleep(50);
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
    if(size <= 0)
    {
        return ;
    }
    file.close();

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

    //上传图片入队
    this->splite->appendQueue(current_date.toStdString() + ".jpg");
    qDebug() << "queueSize = " << this->splite->QueueSize();
}

bool CamDecode::getIsRecord() const
{
    return isRecord;
}

void CamDecode::setIsRecord(bool value)
{
    isRecord = value;
}

void CamDecode::setFlag(int value)
{
    flag = value;
}

string CamDecode::getUserid() const
{
    return userid;
}

void CamDecode::setUserid(const string &value)
{
    userid = value;
    //文件拆分线程保存用户id
    this->splite->setUserid(userid);
}

void CamDecode::MainClose()
{
    //先暂停视频录制
    this->isRecord = false;
    write.release();
    //将此时视频录制的信息发给服务器
    // 视频首帧路径
    strcpy(videoSave.video_cover, coverPath.c_str());
    //告诉服务器保存的视频信息协议体
    //视频路径
    strcpy(videoSave.video_path, filename.toStdString().c_str());
    videoSave.video_num = this->recordNum;  //视频总帧数
    strcpy(videoSave.video_time, current_date.toStdString().c_str());    //视频录制时间
    strcpy(videoSave.user_account, this->userid.c_str()); //用户id
    //视频保存写进write线程
    head.businessType = 5;
    head.businessLength = sizeof (VIDEO_SAVE);
    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &videoSave, sizeof(VIDEO_SAVE));
    WriteThread::getInstance()->setData(head, bodyBuf);

    cout << "video_num" << videoSave.video_num << endl;
    cout << "video_path" << videoSave.video_path << endl;
    cout << "video_time" << videoSave.video_time << endl;
    cout << "video_cover" << videoSave.video_cover << endl;


    this->recordNum = 0;
    //程序关闭了这个线程也要关闭了
    this->isStop = true;
}

void CamDecode::swapWindow()
{
    //先暂停视频录制
    this->isRecord = false;
    write.release();
    //将此时视频录制的信息发给服务器
    // 视频首帧路径
    strcpy(videoSave.video_cover, coverPath.c_str());
    //告诉服务器保存的视频信息协议体
    //视频路径
    strcpy(videoSave.video_path, filename.toStdString().c_str());
    videoSave.video_num = this->recordNum;  //视频总帧数
    strcpy(videoSave.video_time, current_date.toStdString().c_str());    //视频录制时间
    strcpy(videoSave.user_account, this->userid.c_str()); //用户id
    //视频保存写进write线程
    head.businessType = 5;
    head.businessLength = sizeof (VIDEO_SAVE);
    char bodyBuf[2000] = {0};
    memcpy(bodyBuf, &videoSave, sizeof(VIDEO_SAVE));
    WriteThread::getInstance()->setData(head, bodyBuf);

    cout << "video_num" << videoSave.video_num << endl;
    cout << "video_path" << videoSave.video_path << endl;
    cout << "video_time" << videoSave.video_time << endl;
    cout << "video_cover" << videoSave.video_cover << endl;


    this->recordNum = 0;
}


CamDecode::CamDecode()
{
    this->isStop = false;
    this->isRun = false;
    this->isRecord = false;
    //Global variables
    this->isFirstDetectedG = true;
    this->isFirstDetectedR = true;

    //new文件拆分线程
    this->splite = SplitFile::getInstance();

    //倒车模式的私有定义
    this->a = false;
    this->i = 1;
    //调用的摄像头
//    this->cap = new VideoCapture("./Video/car02.mp4");
    this->cap = new VideoCapture(0);
    this->cascade.load("./Tools/cars.xml");
    this->recordNum = 0;
}

void CamDecode::run()
{

    while(!(this->isStop))
    {
        if(this->isRun)
        {
            this->cap->read(this->frame);
            //判断当前是哪个模式
            if(flag==1) //行车
            {
                //识别行车并且绘制边框
                this->detecCarRaw(this->frame, 2);
                //红绿灯
                this->lightDetect(this->frame);
            }
            else if (flag==2)   //倒车
            {
                ObstacleRanging(this->frame);
            }
            else if(flag == 3)
            {

            }


            //录制
            if(this->isRecord)
            {
                qDebug() << "recordNum = " << this->recordNum;
                if(this->recordNum==0)
                {
                    QDateTime current_date_time = QDateTime::currentDateTime();
                    //先记录下开始录制时的时间
                    this->current_date = current_date_time.toString("yyyy_MM_dd_hh_mm_ss");
                    this->filename = "./out/" + current_date + ".avi";
                    qDebug() << "filename = " << filename ;
                    this->coverPath = QString("./out/" + current_date).toStdString() + ".jpg";
                    //保存视频本地首帧图片
                    imwrite(coverPath.c_str(), this->frame);
                    //视频写入本地
                    write.open(filename.toStdString().c_str(), CV_FOURCC('M','J','P','G'), int(round(cap->get(CAP_PROP_FPS))), Size(frame.cols, frame.rows));

                }

                if(this->recordNum<300)
                {
//                    qDebug() << "录制中....";
                    //将这一帧数据写入文件
                    write << frame;
                    this->recordNum++;
                }
                else
                {
                    qDebug() << "已经到300帧 自动结束";
                    this->isRecord = false;

                    write.release();

                    //录制好了300帧我才告诉服务器
                    // 视频首帧路径
                    strcpy(videoSave.video_cover, coverPath.c_str());

                    //告诉服务器保存的视频信息协议体
                    //视频路径
                    strcpy(videoSave.video_path, filename.toStdString().c_str());
                    videoSave.video_num = this->recordNum;  //视频总帧数
                    strcpy(videoSave.video_time, current_date.toStdString().c_str());    //视频录制时间
                    strcpy(videoSave.user_account, this->userid.c_str()); //用户id
                    cout << "video_num" << videoSave.video_num << endl;
                    cout << "video_path" << videoSave.video_path << endl;
                    cout << "video_time" << videoSave.video_time << endl;
                    cout << "video_cover" << videoSave.video_cover << endl;
                    //视频保存写进write线程
                    head.businessType = 5;
                    head.businessLength = sizeof (VIDEO_SAVE);
                    char bodyBuf[2000] = {0};
                    memcpy(bodyBuf, &videoSave, sizeof(VIDEO_SAVE));
                    WriteThread::getInstance()->setData(head, bodyBuf);

                    emit this->TimeStart();

                    this->recordNum = 0;
                }
            }

            if(flag!=3)
            {
                this->img = QImage(frame.data, frame.cols, frame.rows, frame.cols*frame.channels(), QImage::Format_RGB888);
                emit this->sendImg(this->img);
                msleep(40);
            }
            else
            {
                emit this->sendMat(this->frame.clone());
                msleep(40);
            }

//            this->img = QImage(frame.data, frame.cols, frame.rows, frame.cols*frame.channels(), QImage::Format_RGB888);
//            emit this->sendImg(this->img);
//            msleep(40);
        }
    }
    this->cap->release();
    this->write.release();
}
