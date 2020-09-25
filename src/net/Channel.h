//
// Created by yaochuanwang on 9/24/20.
//

#ifndef SIMPLEWEBSERVER_CHANNEL_H
#define SIMPLEWEBSERVER_CHANNEL_H
#include "src/base/noncopyable.h"
#include <functional>
namespace SimpleServer
{
    class EventLoop;
    class Channel : noncopyable
    {
    private:
        using readCallBack = std::function<void()>;
        using writeCallBack = std::function<void()>;
        using connCallBack = std::function<void()>;
    public:
        Channel(EventLoop* loop,int fd);
        Channel(EventLoop* loop);
    public:
        void setEvent(int events) { events_ = events; }
        void setReadBack(readCallBack&& readCallBack) { readCallBack_ = std::move(readCallBack); }
        void setWriteBack(writeCallBack&& writeCallBack) { writeCallBack_ = std::move(writeCallBack); }
        void setConnBakc(connCallBack&& connCallBack) { connCallBack_ = std::move(connCallBack); }

    public:
        int getEvents() const
        {
            return events_;
        }
        int getSockfd() const
        {
            return sockfd_;
        }

    public:
        void handleReadback();
        void handleEvent();
    private:
        int sockfd_;
    public:
        void setSockfd(int sockfd);

    private:
        int events_;
        int revents_;
    public:
        void setRevents(int revents);

    private:
        EventLoop* loop_;
        readCallBack readCallBack_;
        writeCallBack writeCallBack_;
        connCallBack connCallBack_;
    };
}


#endif //SIMPLEWEBSERVER_CHANNEL_H
