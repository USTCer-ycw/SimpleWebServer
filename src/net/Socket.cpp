//
// Created by yaochuanwang on 9/25/20.
//

#include "src/net/Socket.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <memory.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void Socket::setNonBlock(int fd)
{
    int oldfd = ::fcntl(fd,F_GETFL,0);
    oldfd |= O_NONBLOCK;
    fcntl(fd,F_SETFL,oldfd);
}

int Socket::CreateNonBlockFd()
{
    int sockfd = ::socket(AF_INET,SOCK_STREAM,0);
    setNonBlock(sockfd);
    return sockfd;
}

int Socket::BindAndListen(int fd,int port)
{
    sockaddr_in seraddr;
    memset(&seraddr,0,sizeof(seraddr));
    seraddr.sin_addr.s_addr = INADDR_ANY;
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);

    int enable = 1;
    int ret = setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,(void*)&enable,sizeof(enable));
    if(ret<0)
    {
        perror("reuseaddr");
    }
    ret = setsockopt(fd,SOL_SOCKET,SO_REUSEPORT,(void*)&enable,sizeof(enable));
    if(ret < 0)
    {
        perror("reuseport");
    }

    ret = ::bind(fd,(sockaddr*)&seraddr,static_cast<socklen_t>(sizeof(seraddr)));
    if(ret<0)
    {
        perror("bind error");
    }
    ret = listen(fd,SOMAXCONN);
    if(ret < 0)
    {
        perror("listen error");
    }
    return 1;
}

int Socket::acceptSocket(int fd)
{
    struct sockaddr_in client;
    memset(&client,0,sizeof(client));
    socklen_t len = sizeof(client);
    return ::accept(fd,(sockaddr*)&client,&len);
}

int Socket::readmessage(int fd,char* buf)
{
    int n = ::recv(fd,(void*)buf,64,0);
    return n;
}