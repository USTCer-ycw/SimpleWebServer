//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_EVENTLOOP_H
#define SIMPLEWEBSERVER_EVENTLOOP_H

#include "src/net/Epoller.h"
#include "src/base/TimerQueue.h"
using namespace SimpleServer::Time;
namespace SimpleServer
{
    class EventLoop
    {
    public:
        using activeChannels = std::vector<Channel*>;
    public:
        EventLoop();

    public:
        void loop();
        void addChannelToPoller(Channel* channel);
        TimerId runAt(Time::TimeStamp time,Time::TimerCB cb);
        TimerId runAfter(double delay, TimerCB cb);
        TimerId runEvery(double interval, TimerCB cb);
    public:
        void runInLoop();
    private:
        Epoll poller_;
        activeChannels activeChannels_;
        bool quit_;
        std::unique_ptr<TimerQueue> timerQueue_;
    };
}

#endif //SIMPLEWEBSERVER_EVENTLOOP_H
