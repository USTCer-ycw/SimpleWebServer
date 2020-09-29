//
// Created by yaochuanwang on 9/25/20.
//

#include "src/net/Socket.h"
#include <netinet/in.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <memory.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>

void Socket::setNonBlock(int fd)
{
    int oldfd = ::fcntl(fd,F_GETFL,0);
    oldfd |= O_NONBLOCK;
    int ret = fcntl(fd,F_SETFL,oldfd);
    if(ret < 0)
    {
        printf("set nonblock error\n");
    }
}

int Socket::CreateNonBlockFd()
{
    int sockfd = ::socket(AF_INET,SOCK_STREAM,0);
    printf("create listen fd %d\n",sockfd);
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

void Socket::closeFd(int fd)
{
    ::close(fd);


}

int Socket::shutdownWR(int fd)
{
    printf("close write\n");
    return ::shutdown(fd,SHUT_WR);
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
    int n = ::recv(fd,buf,64,0);
    printf("block recv over\n");
    if(n < 0)
    {
        perror("recv error");
        return -1;
    }
    return n;
}

int Socket::sendmsg(int fd, const char *buf)
{
    int n = ::send(fd,buf,strlen(buf),0);
    if(n < 0)
    {
        perror("send error");
        return -1;
    }
    return n;
}

int Socket::Bind(sockaddr_in* addr)
{
    int fd = CreateNonBlockFd();
    int ret = ::bind(fd,(sockaddr*)addr,static_cast<socklen_t>(sizeof(*addr)));
    if(ret < 0)
    {
        perror("bind error");
        return -1;
    }
    return fd;
}

int Socket::Connect(int fd,sockaddr_in* addr)
{
    int ret = ::connect(fd,(sockaddr*)addr,static_cast<socklen_t>(sizeof(*addr)));
    if(ret < 0)
    {
        perror("connect error");
        return -1;
    }
    return 1;
}