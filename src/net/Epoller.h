//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_EPOLLER_H
#define SIMPLEWEBSERVER_EPOLLER_H

#include "sys/epoll.h"
#include <vector>

namespace SimpleServer
{
    class Channel;
    class EventLoop;
    class Epoll
    {
    public:
        using activeChannels = std::vector<Channel*>;
    public:
        Epoll(EventLoop* loop);
        ~Epoll() = default;

    public:
        bool addChannelToPoller(Channel* channel);
        void setEvent(int events);
        activeChannels& poll();
    private:
        int epollfd_;
        struct epoll_event ev_;
//        const int MAXFDS = 100000;
        activeChannels activeChannels_;
        EventLoop* loop_;
        int maxevents_;
        std::vector<struct epoll_event> eventList_;
        std::vector<Channel*> channelMap_;
        int event_;
    };
};

#endif //SIMPLEWEBSERVER_EPOLLER_H
