//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_SERVER_H
#define SIMPLEWEBSERVER_SERVER_H
#include "src/net/Socket.h"
#include <functional>
#include <vector>
#include <memory>
#include <map>
namespace SimpleServer
{
    class EventLoop;
    class Channel;
    class Connection;
    class Server
    {
    public:
        Server(EventLoop* loop,int port);
        virtual ~Server() = default;
    private:
        EventLoop* loop_;
    public:
        void setOnConnect(const onConnectCB& cb) { connectBack_ = cb; }
        void setOnMessage(const onMessageCB& cb) { messageBack_ = cb; }
    public:
        void start();

    private:
        onConnectCB connectBack_;
        onMessageCB messageBack_;
    public:
        void handleConn();
        void handleNewConn();
        void handleRead();
        void handleReadMsg(char* buf);
        void defaultMeeageCB(const ConnectionPtr &conn);
        void defaultConnectCB(const ConnectionPtr& conn);
    private:
        using activeChanels = std::vector<Channel*>;
        using ConnectionMap = std::map<int,ConnectionPtr>;
    private:
        Channel* acceptChannel_;
        int acceptfd_;
        activeChanels activeChanels_;
        std::vector<Connection*> connectList_;
        ConnectionMap connectionMap_;
    };
}

#endif //SIMPLEWEBSERVER_SERVER_H
