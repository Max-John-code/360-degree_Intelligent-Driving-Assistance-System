#ifndef SENDTASK_H
#define SENDTASK_H

#include <QRunnable>
#include <unistd.h>
#include <cstring>
#include "protocol.h"
#include <QDebug>

class SendTask : public QRunnable
{
public:
    SendTask();
    SendTask(FILEINFO &fileinfo, int socketfd);

    uint32_t crc32(const char *data, size_t size);

    // QThread interface
protected:
    void run();
private:
    int socketfd;
    char buf[2000];
    FILEINFO fileinfo;
    HEAD head;
};

#endif // SENDTASK_H
