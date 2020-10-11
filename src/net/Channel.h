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
    private:
        using readCallBack = std::function<void()>;
        using readMsgCallBack = std::function<void(char*)>;
        using connNewCallBack = std::function<void(Channel*)>;
        using writeCallBack = std::function<void()>;
        using connCallBack = std::function<void()>;
        using onMessageBack = std::function<void(Connection&)>;
        using msgCallBack = std::function<void(Channel *)>;
    public:
        Channel(EventLoop *loop, int fd);
        Channel(EventLoop* loop);
    public:
        void setEvent(int events) { events_ = events; }
        void setReadBack(readCallBack&& readCallBack) { readCallBack_ = std::move(readCallBack); }
        void setReadMsgBack(readMsgCallBack&& readMsgCallBack) { readMsgCallBack_ = std::move(readMsgCallBack); }
        void setWriteBack(writeCallBack&& writeCallBack) { writeCallBack_ = std::move(writeCallBack); }
        void setConnBack(connCallBack&& connCallBack) { connCallBack_ = std::move(connCallBack); }
        void setConnNewBack(connNewCallBack&& connNewCallBack) { connNewCallBack_ = std::move(connNewCallBack); }
        void setMessageBack(onMessageBack&& cb) { messageBack_ = std::move(cb); }
        void setmsgCallBack(const msgCallBack& cb) { msgCallBack_ = cb; }


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
        readCallBack readCallBack_;
        readMsgCallBack readMsgCallBack_;
        writeCallBack writeCallBack_;
        connCallBack connCallBack_;
        connNewCallBack connNewCallBack_;
        onMessageBack messageBack_;
        msgCallBack msgCallBack_;
//        char* buffer_;
        Socket::Buffer::size_type defaultsize_;
        Socket::Buffer buffer_;
    };
}


#endif //SIMPLEWEBSERVER_CHANNEL_H
