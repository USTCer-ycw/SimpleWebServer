//
// Created by yaochuanwang on 9/24/20.
//

#ifndef SIMPLEWEBSERVER_CHANNEL_H
#define SIMPLEWEBSERVER_CHANNEL_H
#include "src/base/noncopyable.h"
#include "src/net/Socket.h"
#include <functional>
#include <memory>
namespace SimpleServer
{
    class EventLoop;
    class Connection;
    class Channel : noncopyable,std::enable_shared_from_this<Channel>
    {
    public:
        Channel(EventLoop *loop, int fd);
        Channel(EventLoop* loop);

    public:
        void setEvent(int events) { events_ = events; }
        void sethandleRead(handleRead&& cb) { readcallback_ = cb; }
        void sethandleWrite(handleWrite&& cb) { writecallback_ = cb; }
        void sethandleError(handleError&& cb) { errorcallback_ = cb; }
        void sethandleClose(handleClose&& cb) { closecallback_ = cb; }
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
        Socket::Buffer& getInput();
        void send(Socket::Buffer &msg);
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
        handleRead readcallback_;
        handleWrite writecallback_;
        handleError errorcallback_;
        handleClose closecallback_;
//        char* buffer_;
        Socket::Buffer::size_type defaultsize_;
        Socket::Buffer buffer_;
    };
}


#endif //SIMPLEWEBSERVER_CHANNEL_H
