//
// Created by yaochuanwang on 10/4/20.
//

#include "src/net/Connection.h"
#include "src/net/Channel.h"
#include "src/net/Epoller.h"
#include "src/net/EventLoop.h"
using namespace SimpleServer;

//use for UDP
Connection::Connection(EventLoop *loop) :
loop_(loop),
defaultsize_(128)
{
    channelptr_.reset(new Channel(loop_));
    channelptr_->sethandleError(std::bind(&Connection::handleRead, this));
    channelptr_->setEvent(EPOLLIN | EPOLLRDHUP);
    buffer_.resize(defaultsize_);
}

Connection::Connection(EventLoop *loop,int acceptfd) :
loop_(loop),
acceptedfd_(acceptfd),
defaultsize_(128)
{
    buffer_.resize(defaultsize_);
    channelptr_.reset(new Channel(loop_, acceptedfd_));
    channelptr_->sethandleRead(std::bind(&Connection::handleRead, this));
    channelptr_->sethandleWrite(std::bind(&Connection::handleWrite, this));
    channelptr_->setEvent(EPOLLIN | EPOLLPRI);
    loop_->addChannelToPoller(channelptr_.get());
}

Connection::~Connection()
{
}

void Connection::handleRead()
{
    int n = Socket::readmessage(channelptr_->getSockfd(), buffer_);
    if (n > 0 )
    {
        {
            ConnectionPtr GuardPtr = shared_from_this();
            messageCB_(GuardPtr);
        }
    }
}

void Connection::shutdownWR()
{
    Socket::shutdownWR(channelptr_->getSockfd());
}

std::string Connection::getPeer()
{
    return Socket::getPeerInfo(channelptr_->getSockfd());
}

Socket::Buffer & Connection::getInput()
{
    return buffer_;
}

void Connection::send(Socket::Buffer &buffer)
{

}

void Connection::handleWrite()
{

}
