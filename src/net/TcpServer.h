//
// Created by yaochuanwang on 9/26/20.
//

#ifndef SIMPLEWEBSERVER_TCPSERVER_H
#define SIMPLEWEBSERVER_TCPSERVER_H
#include "src/net/Server.h"
namespace SimpleServer
{
    class TcpServer : public Server
    {
    private:
        using activeChannels = std::vector<Channel*>;
        using readCallBack = std::function<void(char*)>;
    public:
        TcpServer(EventLoop* loop,int port);
        ~TcpServer() = default;

    public:
        void setReadCallBack(const readCallBack& readCallBack);
    private:
        void handleRead();
        void hanleWrite();
        void haneleConn();

    private:
        readCallBack readCallBack_;
//        writeCallBack writeCallBack_;
//        connCallBack connCallBack_;
    };
}

#endif //SIMPLEWEBSERVER_TCPSERVER_H
