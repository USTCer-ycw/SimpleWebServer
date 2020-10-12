//
// Created by yaochuanwang on 9/29/20.
//

#include "src/net/Client.h"
#include "src/net/Socket.h"
#include <memory.h>
#include "src/net/Channel.h"
#include "src/net/EventLoop.h"
using namespace SimpleServer;

Client::Client(EventLoop* loop,string ip, int port) :
ip_(ip),
port_(port),
loop_(loop),
connectchannel_(new Channel(loop))
{
    fd_ = Socket::CreateNonBlockFd();
    connectchannel_->setSockfd(fd_);
    connectchannel_->setEvent(EPOLLIN  | EPOLLPRI | EPOLLRDHUP | EPOLLOUT | EPOLLET);
//    connectchannel_->sethandleRead(std::bind(&Client::defaultreadback,this,std::placeholders::_1));
    loop_->addChannelToPoller(connectchannel_.get());
    memset(&clientaddr_,0,sizeof(clientaddr_));
    clientaddr_.sin_family = AF_INET;
    clientaddr_.sin_addr.s_addr = inet_addr(ip.c_str());
    clientaddr_.sin_port = htons(port);
}

Client::~Client()
{
}

int Client::connect()
{
    Socket::Connect(fd_,&clientaddr_);
    int error = errno;
    switch (error)
    {
        case EISCONN:
            fprintf(stdout,"connected\n");
            break;
        case EINPROGRESS:
        {
            printf("IN\n");
            int err;
            socklen_t len = sizeof(err);
            getsockopt(fd_,SOL_SOCKET,SO_ERROR,&err,&len);
            printf("err:%d\n",err);
        }

            break;
        case EAGAIN:
            printf("AG\n");
            break;
        case EADDRINUSE:
            printf("ADDRINUSE\n");
            break;
        case EADDRNOTAVAIL:
            printf("ADDRNOTAVAIL\n");
            break;
        case ECONNREFUSED:
            printf("CONNREFUSED\n");
            break;
        case ENETUNREACH:
            printf("ETUN\n");
            break;
        default:
            perror("connect error");
            break;
    }
}


void Client::handleread(char* buf)
{
    readCallBack_(buf);
}

void Client::defaultreadback(char *buf)
{
    Socket::readmessage(fd_,buf);
    printf("recv:%s\n",buf);
}

void Client::handlewrite(char *buf)
{
    sendStr(buf);
}

void Client::sendStr(const string&& msg)
{
    msg_ = std::move(msg);
}

void Client::setReadCallBack(const Client::ReadCallBack &readCallBack)
{
    readCallBack_ = readCallBack;
//    connectchannel_->setReadMsgBack(std::bind(&Client::handleread,this,std::placeholders::_1));
}

void Client::setWriteCallBack(const Client::WriteCallBack &writeCallBack)
{
    writeCallBack_ = writeCallBack;
}


