#ifndef SPLITFILE_H
#define SPLITFILE_H

#include <QThread>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <QDebug>
#include <dirent.h>
#include <iostream>
#include "Thread/sendtask.h"
#include <QThreadPool>
#include "protocol.h"
#include <fstream>
#include "socketconnect.h"
#include "Thread/writethread.h"
#include <QQueue>
#include "Thread/readthread.h"

using namespace std;

class SplitFile : public QThread
{
    Q_OBJECT
public:
    static SplitFile* splitTh;
    static SplitFile* getInstance();
    //文件拆分函数
//    void fileSplit(string username, QString path, QString filename);
    //文件合并函数
    void fileMerge(QString path);

    QString getFilename() const;
    void setFilename(const QString &value);

    void appendQueue(string file);     //用于外部进队列
    int QueueSize();
    //取出丢包需要重发的碎片下标函数
    vector<string> split(string str);

    void setUserid(const string &value);

private:
    SplitFile();
    SocketConnect* socketfd;
    int rfd, wfd;    //文件读写
    char buf[1000];

    WriteThread* wth;
    ReadThread* rth;

    FILEINFO fileinfo;    //文件上传结构体
    FILE_FINISH finish;   //文件发送确认结构体
    PHOTO photo;    //第十五个协议，数据库存进数据库
    HEAD head;
    string userid;
    QString filename;
    QQueue<string> fileQueue;    //队列村文件
    list<FILEINFO> fileList;    //碎片链表
    map<int,FILEINFO> fileMap;
    int lossFlag;   //标记是否处理完丢包问题


    // QThread interface
protected:
    void run();
public slots:
    void emitLossFile(FILE_LOSS);
};

#endif // SPLITFILE_H
