//
// Created by yaochuanwang on 9/25/20.
//

#include "EventLoop.h"
#include "src/net/Channel.h"
#include "src/base/Logging.h"
using namespace SimpleServer;

EventLoop::EventLoop() :
poller_(this),
quit_(false),
timerQueue_(new TimerQueue(this))
{
}

void EventLoop::loop()
{
//    int event = EPOLLIN | EPOLLOUT;
////    poller_.setEvent(event);
//    poller_.addChannelToPoller(acceptChannel_);
    while(!quit_)
    {
        activeChannels_ = poller_.poll();
        runInLoop();
    }
}

void EventLoop::addChannelToPoller(Channel *channel)
{
    bool ret = poller_.addChannelToPoller(channel);
    if(!ret)
    {
        LOG << "add to Epoll error";
    }
}

void EventLoop::runInLoop()
{
    for(int i=0;i<activeChannels_.size();++i)
    {
//        activeChannels_[i]->setReadHandler(std::bind())
        activeChannels_[i]->handleEvent();
    }
}

TimerId EventLoop::runAt(Time::TimeStamp time, Time::TimerCB cb)
{
    return timerQueue_->addTimer(cb, time, 0);
//    timerQueue_->addTimer(cb, time, 0);
}

TimerId EventLoop::runAfter(double delay, TimerCB cb)
{
    TimeStamp time(addTime(TimeStamp::now(), delay));
    return runAt(time, cb);
}

TimerId EventLoop::runEvery(double interval, TimerCB cb)
{
    TimeStamp time(addTime(TimeStamp::now(), interval));
    return timerQueue_->addTimer(cb, time, interval);
//    timerQueue_->addTimer(cb, time, interval);
}