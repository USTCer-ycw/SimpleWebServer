//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_SERVER_H
#define SIMPLEWEBSERVER_SERVER_H
#include <functional>
#include <vector>
namespace SimpleServer
{
    class EventLoop;
    class Channel;
    class Server
    {
    public:
        using readCallBack = std::function<void()>;
        using readMsgCallBack = std::function<void(char*)>;
        using writeCallBack = std::function<void()>;
        using connCallBack = std::function<void()>;
    public:
        Server(EventLoop* loop,int port);
        ~Server() = default;
    private:
        EventLoop* loop_;
    public:
        void setReadCallBack(const readCallBack &readCallBack);

        void setReadMsgCallBack(const readMsgCallBack& readMsgCallBack);

        void setWriteCallBack(const writeCallBack &writeCallBack);

        void setConnCallBack(const connCallBack &connCallBack);

    public:
        void start();

    private:
        readCallBack readCallBack_;
        readMsgCallBack readMsgCallBack_;
        writeCallBack writeCallBack_;
        connCallBack connCallBack_;

    public:
        void handleConn();
        void handleRead();
        void handleReadMsg(char* buf);

    private:
        using activeChanels = std::vector<Channel*>;

    private:
        Channel* acceptChannel_;
        activeChanels activeChanels_;
    };
}

#endif //SIMPLEWEBSERVER_SERVER_H
