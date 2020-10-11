//
// Created by yaochuanwang on 9/29/20.
//

#ifndef SIMPLEWEBSERVER_CLIENT_H
#define SIMPLEWEBSERVER_CLIENT_H

#include <string>
#include <memory>
#include <functional>
#include <arpa/inet.h>
using std::string;
namespace SimpleServer
{
    class EventLoop;
    class Channel;
    class Client
    {
    private:
        using ReadCallBack = std::function<void(char*)>;
        using WriteCallBack = std::function<void(char*)>;
    public:
        Client(EventLoop* loop,string ip,int port);
        ~Client();

    public:
        void sendStr(const string&& msg);
        void sendBinStr(const string& msg);
        int connect();

    private:
        ReadCallBack readCallBack_;
    public:
        void setReadCallBack(const ReadCallBack &readCallBack);

        void setWriteCallBack(const WriteCallBack &writeCallBack);

    private:
        WriteCallBack writeCallBack_;
    public:

    private:
        void handleread(char* buf);
        void handlewrite(char* buf);
        void defaultreadback(char* buf);
    private:
        EventLoop* loop_;
        int fd_;
        int port_;
        string ip_;
        string msg_;
        std::unique_ptr<Channel> connectchannel_;
        struct sockaddr_in clientaddr_;
    };
}

#endif //SIMPLEWEBSERVER_CLIENT_H
