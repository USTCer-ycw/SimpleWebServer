//
// Created by yaochuanwang on 9/24/20.
//

#include "src/net/Channel.h"
#include "src/net/Epoller.h"
#include "src/net/Socket.h"
using namespace SimpleServer;

Channel::Channel(EventLoop *loop):
loop_(loop)
{

}

Channel::Channel(EventLoop *loop, int fd):
loop_(loop),
sockfd_(fd)
{}

void Channel::handleReadback()
{
    if(readCallBack_)
        readCallBack_();
}

void Channel::handleEvent()
{
    Socket::acceptSocket(sockfd_);
    if(revents_ & EPOLLIN)
        handleReadback();
}

void Channel::setSockfd(int sockfd)
{
    sockfd_ = sockfd;
}

void Channel::setRevents(int revents)
{
    revents_ = revents;
}
