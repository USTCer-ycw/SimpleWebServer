//
// Created by yaochuanwang on 10/4/20.
//

#ifndef SIMPLEWEBSERVER_TCPCONNECT_H
#define SIMPLEWEBSERVER_TCPCONNECT_H

#include "src/base/noncopyable.h"
#include "src/net/Socket.h"
#include <memory>
#include <functional>
namespace SimpleServer
{
    class EventLoop;
    class Channel;
    class Connection : private noncopyable, public std::enable_shared_from_this<Connection>
    {
    public:
        Connection(EventLoop *loop);
        Connection(EventLoop *loop,int acceptfd);
        virtual ~Connection();
    public:
        int operator()(const Connection &connection) const;
        void send(Socket::Buffer &buffer);
        Socket::Buffer &getInput();
        void shutdownWR();
        void setOnMessageCB(const onMessageCB& cb) { messageCB_ = cb; }
        void setOnConnectCB(const onConnectCB& cb) { connectCB_  = cb;}
        std::string getPeer();
    private:
        void handleRead();
        void handleWrite();
        void handleError();
        void handleClose();
    private:
        onMessageCB messageCB_;
        onConnectCB connectCB_;
    private:
        EventLoop* loop_;
        int defaultsize_;
        Socket::Buffer buffer_;
        ChannelPtr channelptr_;
        int acceptedfd_;
    };
    using ConnectionPtr = std::shared_ptr<Connection>;
}

#endif //SIMPLEWEBSERVER_TCPCONNECT_H
