#include "readthread.h"

ReadThread* ReadThread::rth = nullptr;

ReadThread* ReadThread::getInstance()
{
    if(ReadThread::rth == nullptr)
    {
        ReadThread::rth = new ReadThread;
    }
    return ReadThread::rth;
}

ReadThread::ReadThread()
{
    memset(&head, 0, sizeof(head));
    memset(&loginBack, 0, sizeof(LOGIN_BACK));
    memset(buf, 0, sizeof(buf));
}

void ReadThread::run()
{
    // 注册类型
    qRegisterMetaType<GET_PHOTOS_INFO>();
    qRegisterMetaType<FILE_LOSS>();
    qRegisterMetaType<BACK_PAGE>();
    while(true)
    {
        res = read(rfd, buf, sizeof(HEAD));
        qDebug() << "read res = " << res;

        if(res == -1)
        {
            emit setFail();
            return ;
        }
        //心跳断开
        if(res==0)
        {
            emit heartLoss();
            return ;
        }
        if(res == sizeof (HEAD))
        {
            memcpy(&head, buf, sizeof(HEAD));

            qDebug() << "head.businessType = " << head.businessType;
            qDebug() << "head.businessLength = " << head.businessLength;
            //将buf的内容清空再进行读取。读取根据业务类型判断
            bzero(buf, sizeof(buf));


            //注册的返回类型
            //现在改成所有的CRC重发返回
            if (head.businessType == 2)
            {
                res = read(rfd, buf, head.businessLength);
                qDebug() << "regRes = " << res;
                memcpy(&tback, buf, sizeof(TBACK));
                qDebug() << "tback.flag = " << tback.flag;
                if(tback.flag==0)//CRC错误
                {

                }
                else if(tback.flag==1)
                    emit this->regSuccess();
                else if(tback.flag == -1)
                    emit regFail();
            }
            //登录的返回类型
            else if(head.businessType == 4)
            {
                res = read(rfd, buf, head.businessLength);
                qDebug() << "loginRes = " << res;
                memcpy(&loginBack, buf, sizeof(LOGIN_BACK));
                qDebug() << "loginBack.flag = " << loginBack.flag ;
                qDebug() << "loginBack.username = " << loginBack.user_name;
                //flag0代表登陆成功
                if(loginBack.flag==1)
                    //记录用户名显示在主界面
                    emit loginSuccess(loginBack.user_name);
                else if(loginBack.flag==-1)
                    emit loginFail();
                //CRC错误
                else if(loginBack.flag==0)
                {

                }
            }

            //图片查询后信息的返回包
            else if (head.businessType==19)
            {
                res = read(rfd, buf, head.businessLength);
                qDebug() << "Get_PHOTOS_INFO res = " << res;
                memcpy(&photoInfo, buf, sizeof(GET_PHOTOS_INFO));
                //flag判断对错
                qDebug() << "photoInfo.flag = " << photoInfo.flag ;
                //如果错
                emit getPhoto(photoInfo);
            }
            //丢包返回协议体
            else if (head.businessType == 14)
            {
                res = read(rfd, buf, head.businessLength);
                qDebug() << "FILE_LOSS res = " << res;
                memcpy(&fileLoss, buf, sizeof (FILE_LOSS));
                qDebug() << "count = " << fileLoss.count;
                qDebug() << "cur = " << fileLoss.cur;
                //打印一下看有没有丢包
                qDebug() << "fileLoss.fileCount = " << fileLoss.fileCount;
                emit packLoss(fileLoss);
            }
            //视频翻页返回协议体
            else if(head.businessType == 7)
            {
                res = read(rfd, buf, head.businessLength);
                qDebug() << "BACK_PAGE res = " << res;
                memcpy(&backPage, buf, head.businessLength);
                qDebug() << "backPage.flag = " << backPage.flag ;
                emit emitBackPage(backPage);
            }
        }
    }
}

int ReadThread::getRfd() const
{
    return rfd;
}

void ReadThread::setRfd(int value)
{
    rfd = value;
}
