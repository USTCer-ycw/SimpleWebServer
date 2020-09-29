//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_SOCKET_H
#define SIMPLEWEBSERVER_SOCKET_H

#include <arpa/inet.h>

namespace Socket
{
    void setNonBlock(int fd);
    int CreateNonBlockFd();
    int BindAndListen(int fd,int port);
    int acceptSocket(int fd);
    int readmessage(int fd,char* buf);
    void closeFd(int fd);
    int shutdownWR(int fd);
    int sendmsg(int fd,const char* buf);
    int Bind(sockaddr_in* addr);
    int Connect(int fd,sockaddr_in* addr);
}
#endif //SIMPLEWEBSERVER_SOCKET_H
