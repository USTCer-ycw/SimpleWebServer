//
// Created by yaochuanwang on 9/25/20.
//

#include "EventLoop.h"
#include "src/net/Channel.h"
using namespace SimpleServer;

EventLoop::EventLoop() :
poller_(this)
{
}

void EventLoop::loop()
{
    int event = EPOLLIN | EPOLLOUT;
    poller_.setEvent(event);
    activeChannels_ = poller_.poll();
    runInLoop();
}

void EventLoop::runInLoop()
{
    for(int i=0;i<activeChannels_.size();++i)
    {
        activeChannels_[i]->setReadBack(std::bind())
        activeChannels_[i]->handleEvent();
    }
}