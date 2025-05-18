#include "heartbeatthread.h"

HeartbeatThread* HeartbeatThread::heartTh = nullptr;

HeartbeatThread *HeartbeatThread::getInstance()
{
    if(HeartbeatThread::heartTh == nullptr)
    {
        HeartbeatThread::heartTh = new HeartbeatThread;
    }
    return HeartbeatThread::heartTh;
}

HeartbeatThread::HeartbeatThread()
{
    this->isRun = false;
    this->count = 0;
    this->wth = WriteThread::getInstance();
    head.businessType = 10;
    head.businessLength = 0;
}

void HeartbeatThread::setIsRun(bool value)
{
    isRun = value;
}

void HeartbeatThread::run()
{
    char bodyBuf[10] = {0};
    while(true)
    {
        if(this->isRun)
        {
//            this->wth->setData(head,bodyBuf);
            msleep(1000);
//            std::cout << "count = " << count << std::endl;
            this->count++;
            if(this->count==15)
            {
                this->wth->setData(head,bodyBuf);
                this->count = 0;
            }
        }
    }
}
