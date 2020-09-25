//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_EVENTLOOP_H
#define SIMPLEWEBSERVER_EVENTLOOP_H

#include "src/net/Epoller.h"
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

    public:
        void runInLoop();
    private:
        Epoll poller_;
        activeChannels activeChannels_;
    };
}

#endif //SIMPLEWEBSERVER_EVENTLOOP_H
