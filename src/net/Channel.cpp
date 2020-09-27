//
// Created by yaochuanwang on 9/24/20.
//

#include "src/net/Channel.h"
#include "src/net/Epoller.h"
#include "src/net/Socket.h"
#include "src/net/EventLoop.h"
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
    char buf[64] = {'\0'};
    int connfd = Socket::acceptSocket(this->getSockfd());
    Socket::setNonBlock(connfd);
    Channel* ch = new Channel(loop_,connfd);
    ch->setEvent(EPOLLIN | EPOLLOUT);
    ch->readMsgCallBack_ = this->readMsgCallBack_;
    loop_->addChannelToPoller(ch);
    Socket::readmessage(connfd,buf);
    readMsgCallBack_(buf);
//    printf("%s\n",buf);
//    if(readCallBack_)
//        readCallBack_();
}

void Channel::handleEvent()
{
//    loop_->acceptChannel_ = 0;
//    printf("conn fd:%d\n",connfd);
    if(revents_ & EPOLLIN)
        handleReadback();
    if(revents_ & EPOLLOUT)
        printf("EPOLLOUT\n");
    else
        Socket::closeFd(sockfd_);
}

void Channel::setSockfd(int sockfd)
{
    sockfd_ = sockfd;
}

void Channel::setRevents(int revents)
{
    revents_ = revents;
}
