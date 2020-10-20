//
// Created by yaochuanwang on 9/25/20.
//

#include "src/net/Epoller.h"
#include "src/net/Channel.h"
using namespace SimpleServer;

Epoll::Epoll(EventLoop* loop) :
loop_(loop),
maxevents_(100),
eventList_(maxevents_),
channelMap_(maxevents_)
{
    epollfd_ = ::epoll_create1(EPOLL_CLOEXEC);
}

bool Epoll::addChannelToPoller(Channel* channel)
{
    ev_.events = channel->getEvents();
    ev_.data.fd = channel->getSockfd();
    printf("fd:%d\n", channel->getSockfd());
    channelMap_[channel->getSockfd()] = channel;
    return epoll_ctl(epollfd_,EPOLL_CTL_ADD,channel->getSockfd(),&ev_) == 0;
}

void Epoll::setEvent(int events)
{
    ev_.events = events | EPOLLET;
    ev_.data.fd = 4;
    epoll_ctl(epollfd_,EPOLL_CTL_ADD,4,&ev_);
}

SimpleServer::Epoll::activeChannels & Epoll::poll()
{
    int nums = ::epoll_wait(epollfd_,&*eventList_.begin(),maxevents_,-1);
    activeChannels_.clear();
    for(int i=0;i<nums;++i)
    {
        Channel* ch = channelMap_[eventList_[i].data.fd];
        ch->setRevents(eventList_[i].events);
        activeChannels_.push_back(ch);
//        activeChannels_.emplace_back(new Channel(loop_,eventList_[i].data.fd));
//        activeChannels_[i]->setRevents(eventList_[i].events);
    }
    return activeChannels_;
}
