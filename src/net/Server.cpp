//
// Created by yaochuanwang on 9/25/20.
//

#include "src/net/Server.h"
#include "src/net/Socket.h"
#include "src/net/Channel.h"
#include "src/net/EventLoop.h"
using namespace SimpleServer;

Server::Server(EventLoop *loop, int port):
loop_(loop),
acceptChannel_(new Channel(loop))
{
    acceptChannel_->setReadBack(std::bind(&Server::handleRead,this));
    acceptChannel_->setSockfd(Socket::CreateNonBlockFd());
    Socket::BindAndListen(acceptChannel_->getSockfd(),port);
    acceptChannel_->setEvent(EPOLLIN | EPOLLOUT |EPOLLET);
}

void Server::start()
{
    using std::placeholders::_1;
    acceptChannel_->setConnBakc(std::bind(&Server::handleConn,this));
    acceptChannel_->setReadMsgBack(std::bind(&Server::handleReadMsg,this,_1));
    loop_->addChannelToPoller(acceptChannel_);
}

void Server::handleRead()
{
    char message[64];
    int fd = acceptChannel_->getSockfd();
    Socket::readmessage(fd,message);
    printf("%s\n",message);
}

void Server::handleReadMsg(char* buf)
{
    readMsgCallBack_(buf);
}

void Server::handleConn()
{
    printf("new Conn\n");
}

void Server::setReadCallBack(const Server::readCallBack &readCallBack)
{
    readCallBack_ = readCallBack;
}

void Server::setReadMsgCallBack(const readMsgCallBack &readMsgCallBack)
{
    readMsgCallBack_ = readMsgCallBack;
}

void Server::setWriteCallBack(const Server::writeCallBack &writeCallBack)
{
    writeCallBack_ = writeCallBack;
}

void Server::setConnCallBack(const Server::connCallBack &connCallBack)
{
    connCallBack_ = connCallBack;
}
