#ifndef HEARTBEATTHREAD_H
#define HEARTBEATTHREAD_H

#include <QThread>
#include "protocol.h"
#include "Thread/writethread.h"
#include <iostream>

class HeartbeatThread : public QThread
{
    Q_OBJECT
public:
    static HeartbeatThread *getInstance();
    static HeartbeatThread* heartTh;
    void setIsRun(bool value);

private:
    HeartbeatThread();

    bool isRun;
    int count;
    WriteThread * wth;

    HEAD head;

    // QThread interface
protected:
    void run();
};

#endif // HEARTBEATTHREAD_H
