#ifndef SOCKETCONNECT_H
#define SOCKETCONNECT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>
#include <QDebug>
#include <QString>
#include <QObject>

class SocketConnect : public QObject
{
    Q_OBJECT
public:
    static SocketConnect * sc;
    static SocketConnect * getInstance();
    void Socketinet(QString IP, QString port);
    void closeSocket();
    int getSocketfd() const;

private:
    SocketConnect();
    struct sockaddr_in addr;
    int len;
    int socketfd;
signals:
    //设置界面网络配置失败
    void setFail();
    void setSuccess();
};

#endif // SOCKETCONNECT_H
