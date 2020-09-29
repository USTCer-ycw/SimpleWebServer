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
    if(readMsgCallBack_)
    {
        int n = Socket::readmessage(sockfd_,buf);
        printf("read %d bytes\n",n);
        readMsgCallBack_(buf);
    }
    else
    {
        readCallBack_();
    }
//    if(sockfd_ == 4)
//    {
//        int connfd = Socket::acceptSocket(this->getSockfd());
////    Socket::setNonBlock(connfd);
//        Channel* ch = new Channel(loop_,connfd);
//        ch->setEvent(EPOLLIN | EPOLLRDHUP | EPOLLHUP);
//        ch->readMsgCallBack_ = this->readMsgCallBack_;
//        loop_->addChannelToPoller(ch);
//        Socket::readmessage(connfd,buf);
//        readMsgCallBack_(buf);
//    }
//    else
//    {
//        Socket::readmessage(sockfd_,buf);
//        readMsgCallBack_(buf);
//    }

//    readMsgCallBack_(buf);
//    printf("%s\n",buf);
//    if(readCallBack_)
//        readCallBack_();
}

void Channel::handleEvent()
{
//    loop_->acceptChannel_ = 0;
//    printf("conn fd:%d\n",connfd);
const int IN_BUT_PEER_CLOSE = EPOLLIN & (~EPOLLRDHUP);
printf("revent:%d\n",revents_);
    if(revents_ & EPOLLRDHUP){
        Socket::shutdownWR(sockfd_);
    }
    if(revents_ & EPOLLHUP)
    {
        Socket::closeFd(sockfd_);
        return;
    }
    if(revents_ & (EPOLLIN | EPOLLPRI) && !(revents_ & EPOLLRDHUP))
        handleReadback();
    else if(revents_ & EPOLLOUT)
        printf("EPOLLOUT\n");
}

void Channel::setSockfd(int sockfd)
{
    sockfd_ = sockfd;
}

void Channel::setRevents(int revents)
{
    revents_ = revents;
}
