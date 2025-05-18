#include "sendtask.h"

SendTask::SendTask()
{

}

uint32_t SendTask::crc32(const char *data, size_t size)
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

SendTask::SendTask(FILEINFO &fileinfo, int socketfd)
{

//    head.CRC = crc32(reinterpret_cast<char*>(&fileinfo),  sizeof(FILEINFO));

//    memcpy(&(this->fileinfo), &fileinfo, sizeof (FILEINFO));
//    memcpy(this->buf, &head, sizeof (HEAD));
//    memcpy(this->buf + sizeof (HEAD), &fileinfo, sizeof (FILEINFO));
    this->socketfd = socketfd;
    memcpy(&(this->fileinfo), &fileinfo, sizeof (FILEINFO));

    bzero(this->buf, sizeof (this->buf));
    head.businessType = 12;
    head.businessLength = sizeof (FILEINFO);
    char crcBuf[2000] = {0};
    memcpy(crcBuf, &(this->fileinfo), sizeof (FILEINFO));
    head.CRC = crc32(crcBuf, sizeof (FILEINFO));
    qDebug() << "CRC = " << head.CRC;
}



void SendTask::run()
{
    memcpy(this->buf, &head, sizeof(HEAD));
    memcpy(this->buf + sizeof (HEAD), &(this->fileinfo), sizeof (FILEINFO));
    int res = write(this->socketfd, this->buf, sizeof(HEAD) + sizeof (FILEINFO));
    if(res < 0)
    {
        perror("write error");
    }
}
