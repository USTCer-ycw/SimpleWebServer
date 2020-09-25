//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_SERVER_H
#define SIMPLEWEBSERVER_SERVER_H
#include <functional>
namespace SimpleServer
{
    class EventLoop;
    class Channel;
    class Server
    {
    public:
        using readCallBack = std::function<void()>;
        using writeCallBack = std::function<void()>;
        using connCallBack = std::function<void()>;
    public:
        Server(EventLoop* loop,int port);
    private:
        EventLoop* loop_;

    public:
        void setReadCallBack(const readCallBack &readCallBack);

        void setWriteCallBack(const writeCallBack &writeCallBack);

        void setConnCallBack(const connCallBack &connCallBack);

    private:
        readCallBack readCallBack_;
        writeCallBack writeCallBack_;
        connCallBack connCallBack_;
    private:
        void handleRead();
        Channel* channel_;
    };
}

#endif //SIMPLEWEBSERVER_SERVER_H
