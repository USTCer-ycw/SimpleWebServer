//
// Created by yaochuanwang on 9/25/20.
//

#include "src/net/Server.h"
#include "src/net/Socket.h"
#include "src/net/Channel.h"
#include "src/net/EventLoop.h"
#include "src/net/Connection.h"
using namespace SimpleServer;

Server::Server(EventLoop *loop, int port):
loop_(loop),
acceptChannel_(new Channel(loop,Socket::CreateNonBlockFd())),
acceptfd_(acceptChannel_->getSockfd())
{
    Socket::BindAndListen(acceptChannel_->getSockfd(),port);
    acceptChannel_->setReadBack(std::bind(&Server::handleRead,this));
    acceptChannel_->setEvent(EPOLLIN | EPOLLET);
}

void Server::start()
{
    using std::placeholders::_1;
    acceptChannel_->setConnBack(std::bind(&Server::handleNewConn,this));
    acceptChannel_->setReadBack(std::bind(&Server::handleNewConn,this));
//    acceptChannel_->setConnNewBack(std::bind(&Server::handleNewConn,this,_1));
//    acceptChannel_->setReadMsgBack(std::bind(&Server::handleReadMsg,this,_1));
    loop_->addChannelToPoller(acceptChannel_);
}

void Server::handleRead()
{
    char message[64];
    int fd = acceptChannel_->getSockfd();
    int n = Socket::readmessage(fd,message);
    printf("%s  line %d\n", __FILE__, __LINE__);
    printf("read %d bytes, %s\n",n,message);
}

void Server::handleReadMsg(char* buf)
{
    if(readCallBack_)
        readMsgCallBack_(buf);
}

void Server::handleConn()
{

    if(connCallBack_)
        connCallBack_();
    else
    {
       printf("new conn\n");
    }

//    channel->setSockfd(Socket::acceptSocket())
//    channel->setReadMsgBack(std::bind())
}

void Server::handleNewConn()
{
    Channel* channel = new Channel(loop_);
    channel->setSockfd(Socket::acceptSocket(acceptfd_));
    Socket::setNonBlock(channel->getSockfd());
    channel->setReadMsgBack(std::bind(&Server::handleReadMsg,this,std::placeholders::_1));
    channel->setmsgCallBack(msgCallBack_);
    channel->setEvent(EPOLLIN | EPOLLET);
    loop_->addChannelToPoller(channel);
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

void Server::setConnNewCallBack(const connNewCallBack &connNewCallBack)
{
    connNewCallBack_ = connNewCallBack;
}