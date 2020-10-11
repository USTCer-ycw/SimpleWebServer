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
    class Connection;
    class Server
    {
    public:
        using readCallBack = std::function<void()>;
        using readMsgCallBack = std::function<void(char*)>;
        using connNewCallBack = std::function<void(Channel*)>;
        using writeCallBack = std::function<void()>;
        using connCallBack = std::function<void()>;
        using onMessageBack = std::function<void (Connection&)>;
        using msgCallBack = std::function<void(Channel*)>;
    public:
        Server(EventLoop* loop,int port);
        virtual ~Server() = default;
    private:
        EventLoop* loop_;
    public:
        void setReadCallBack(const readCallBack &readCallBack);

        void setReadMsgCallBack(const readMsgCallBack& readMsgCallBack);

        void setWriteCallBack(const writeCallBack &writeCallBack);

        void setConnCallBack(const connCallBack &connCallBack);

        void setConnNewCallBack(const connNewCallBack &connNewCallBack);

        void setMessageBack(const onMessageBack& cb) { messageBack_ = cb; }

        void setmsgCallBack(const msgCallBack& cb) { msgCallBack_ = cb; }

    public:
        void start();

    private:
        readCallBack readCallBack_;
        readMsgCallBack readMsgCallBack_;
        writeCallBack writeCallBack_;
        connCallBack connCallBack_;
        connNewCallBack connNewCallBack_;
        onMessageBack messageBack_;
        msgCallBack msgCallBack_;
    public:
        void handleConn();
        void handleNewConn();
        void handleRead();
        void handleReadMsg(char* buf);

    private:
        using activeChanels = std::vector<Channel*>;

    private:
        Channel* acceptChannel_;
        int acceptfd_;
        activeChanels activeChanels_;
        std::vector<Connection*> connectList_;
    };
}

#endif //SIMPLEWEBSERVER_SERVER_H
