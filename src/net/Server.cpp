//
// Created by yaochuanwang on 9/25/20.
//

#include "Server.h"
#include "src/net/Socket.h"
#include "src/net/Channel.h"
using namespace SimpleServer;

Server::Server(EventLoop *loop, int port):
loop_(loop),
channel_(new Channel(loop))
{
    channel_->setReadBack(std::bind(&Server::handleRead,this));
    channel_->setSockfd(Socket::CreateNonBlockFd());
    Socket::BindAndListen(channel_->getSockfd(),port);
}

void Server::handleRead()
{
    char message[64];
    int fd = channel_->getSockfd();
    Socket::readmessage(fd,message);
    printf("%s\n",message);
}

void Server::setReadCallBack(const Server::readCallBack &readCallBack)
{
    readCallBack_ = readCallBack;
}

void Server::setWriteCallBack(const Server::writeCallBack &writeCallBack)
{
    writeCallBack_ = writeCallBack;
}

void Server::setConnCallBack(const Server::connCallBack &connCallBack)
{
    connCallBack_ = connCallBack;
}
