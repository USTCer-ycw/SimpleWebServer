//
// Created by yaochuanwang on 10/4/20.
//

#ifndef SIMPLEWEBSERVER_TCPCONNECT_H
#define SIMPLEWEBSERVER_TCPCONNECT_H

#include "src/base/noncopyable.h"

namespace SimpleServer
{
    class EventLoop;
    class Channel;
    class Connection : private noncopyable
    {
    public:
        Connection(EventLoop* loop);
        ~Connection();

    private:
        EventLoop* loop_;
        char* buffer_;
        Channel
    };
}

#endif //SIMPLEWEBSERVER_TCPCONNECT_H
