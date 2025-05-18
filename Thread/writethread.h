#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QThread>
#include "protocol.h"
#include <QDebug>
#include <string.h>
#include <unistd.h>

class WriteThread : public QThread
{
public:
    static WriteThread* getInstance();
    static WriteThread* wth;


    int getWfd() const;
    void setWfd(int value);

    void setData(HEAD headBuf, char bodyBuf[]);

    //crc
    uint32_t crc32(const char *data, size_t size);

private:
    WriteThread();

//    HEAD head;
//    LOGIN login;

    int wfd;
    int inputLen;
    char buf[200];


    // QThread interface
protected:
    void run();
};

#endif // WRITETHREAD_H
