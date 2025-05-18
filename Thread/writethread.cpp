#include "writethread.h"

WriteThread* WriteThread::wth = nullptr;

WriteThread* WriteThread::getInstance()
{
    if(WriteThread::wth == nullptr)
    {
        WriteThread::wth = new WriteThread;
    }
    return wth;
}

WriteThread::WriteThread()
{
//    memset(&(this->head), 0, sizeof(this->head));
//    memset(&(this->login), 0, sizeof(this->login));
    bzero(this->buf, sizeof(this->buf));
    this->inputLen = 0;
}

void WriteThread::run()
{
    while (true) {
        if(this->inputLen>0)
        {
            int res = write(this->wfd, this->buf, this->inputLen);
            qDebug() << "write res = " << res;
            if(res>0)
            {
                qDebug() << "发送数据成功res = " << res ;
            }
            this->inputLen = 0;
        }
    }
}

int WriteThread::getWfd() const
{
    return wfd;
}

void WriteThread::setWfd(int value)
{
    wfd = value;
}

uint32_t WriteThread::crc32(const char *data, size_t size)
{
    unsigned char i;
        uint32_t crc=POLY_INIT; /* 计算的初始crc值 */
        const uint32_t polynomial= POLYNOMIAL;

        while(size--)
        {
            crc ^= ((uint32_t)(*data++)<<24);
            for (i=8; i>0; --i)   /* 下面这段计算过程与计算一个字节crc一样 */
            {
                if (crc & 0x80000000)
                    crc = (crc << 1) ^ polynomial;
                else
                    crc = (crc << 1);
            }
        }
        crc=crc^POLY_END;
         return (crc);
}

void  WriteThread::setData(HEAD headBuf, char *bodyBuf)
{
    headBuf.CRC = crc32(bodyBuf,headBuf.businessLength);
    //自定义通信协议 头＋体
    memcpy(buf, &headBuf, sizeof(HEAD));
    memcpy(buf + sizeof(HEAD), bodyBuf, headBuf.businessLength);

    this->inputLen = sizeof(HEAD) + headBuf.businessLength;
    qDebug() << "head.Type = " << headBuf.businessType ;
}
