//
// Created by yaochuanwang on 9/25/20.
//

#ifndef SIMPLEWEBSERVER_SOCKET_H
#define SIMPLEWEBSERVER_SOCKET_H

namespace Socket
{
//    struct sockaddr_in;
    void setNonBlock(int fd);
    int CreateNonBlockFd();
    int BindAndListen(int fd,int port);
    int acceptSocket(int fd);
    int readmessage(int fd,char* buf);
    void closeFd(int fd);
}
#endif //SIMPLEWEBSERVER_SOCKET_H
