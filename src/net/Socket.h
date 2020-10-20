//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_SOCKET_H
#define SIMPLEWEBSERVER_SOCKET_H

#include <arpa/inet.h>
#include <vector>
#include <memory>
#include <functional>
namespace SimpleServer
{
    namespace Time
    {
        class Timer;
        using TimerCB = std::function<void()>;
    }
    class Connection;
    class Channel;
    using ConnectionPtr = std::shared_ptr<Connection>;
    using ChannelPtr = std::shared_ptr<Channel>;
    using onConnectCB = std::function<void(const ConnectionPtr &)>;
    using onMessageCB = std::function<void(const ConnectionPtr &)>;
    using handleRead = std::function<void()>;
    using handleWrite = std::function<void()>;
    using handleError = std::function<void()>;
    using handleClose = std::function<void()>;
}

namespace Socket
{
    const int MAX_SIZE = 128;
    using Buffer = std::vector<char>;
    void setNonBlock(int fd);
    int CreateNonBlockFd();
    int BindAndListen(int fd,int port);
    int acceptSocket(int fd);
    int readmessage(int fd,char* buf);
    int readmessage(int fd, Buffer &buffer);
    int sendmsg(int fd,const char* buf);
    int sendmessage(int fd, char *buf, size_t bytes);
    int sendmessage(int fd, Buffer& buffer);
    void closeFd(int fd);
    int shutdownWR(int fd);
    char* getPeerInfo(int fd);
    int Bind(sockaddr_in* addr);
    int Connect(int fd,sockaddr_in* addr);
}
#endif //SIMPLEWEBSERVER_SOCKET_H
