#include "socketconnect.h"

SocketConnect* SocketConnect::sc = nullptr;

SocketConnect* SocketConnect::getInstance()
{
    if(SocketConnect::sc == nullptr)
    {
        SocketConnect::sc = new SocketConnect;
    }
    return SocketConnect::sc;
}

void SocketConnect::Socketinet(QString IP, QString port)
{
    addr.sin_family = AF_INET;
    //客户端绑定服务器IP地址
    addr.sin_addr.s_addr = inet_addr(IP.toStdString().c_str());
    addr.sin_port = htons(port.toUShort());
    len = sizeof(addr);

    if(::connect(socketfd, (struct sockaddr*)(&addr), len) != -1)
    {
        qDebug() << "客户端连接服务器成功" ;
        emit setSuccess();
        return ;

    }
    perror("connect error");
    qDebug() << "客户端连接服务器失败" ;
    return ;
}

void SocketConnect::closeSocket()
{

}

SocketConnect::SocketConnect()
{
    this->socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(this->socketfd < 0)
    {
        perror("socket error");
    }
    qDebug() << "客户端初始化网络 socketfd = " << this->socketfd ;
}

int SocketConnect::getSocketfd() const
{
    return socketfd;
}
