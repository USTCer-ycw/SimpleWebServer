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
#include <errno.h>
#include "src/base/Logging.h"
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
    LOG << "create fd" << sockfd;
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
    printf("close\n");
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
    int left = 0, sum = 0;
    int n = 0;
    while (true)
    {
        if ((n = ::read(fd, buf, MAX_SIZE)) < 0)
        {
            int savedError = errno;
            if (savedError == EAGAIN || savedError == EWOULDBLOCK)
            {
                return sum;
            }
            else if (savedError == EINTR) continue;
            else
            {
                perror("read error");
                return sum;
            }
        }
        else if (n == 0)
        {
            return sum;
        }
        sum += n;
        buf += MAX_SIZE;
    }
    return sum;
//    int n = ::recv(fd,buf,64,0);
//    printf("block recv over\n");
//    if(n < 0)
//    {
//        perror("recv error");
//        return -1;
//    }
//    return n;
}

int Socket::sendmsg(int fd, const char *buf)
{
//    int n = ::send(fd,buf,strlen(buf),0);
    int n = ::write(fd, buf, strlen(buf));
    if(n < 0)
    {
        perror("send error");
        return -1;
    }
    return n;
}

int Socket::sendmessage(int fd, char *buf, size_t bytes)
{
    int nleft = bytes, nsend = 0;
    int n = 0;
    while (nleft > 0)
    {
        if ((n = ::write(fd, buf, bytes)) < 0)
        {
            int savedErrno = errno;
            if (savedErrno == EAGAIN || savedErrno == EWOULDBLOCK)
            {
                break;
            }
            else if (savedErrno == EINTR)
            {
                continue;
            }
        }
        else if (n == 0)
        {
            break;
        }
        nleft -= n;
        bytes -= n;
        nsend += n;
        buf += n;
    }
    return nsend;
}

int Socket::readmessage(int fd, Buffer &buffer)
{
    int n = 0;
    int curr = 0;
    Buffer::size_type readablesize = buffer.size();
    int sum = 0;
    while (true)
    {
        if ((n = ::read(fd, &buffer[curr], static_cast<size_t>(readablesize))) < 0)
        {
            int savedErrno = errno;
            if (savedErrno == EAGAIN || savedErrno == EWOULDBLOCK)
            {
                buffer.resize(sum);
                return sum;
            }
            else if (savedErrno == EINTR)
            {
                break;
            }
        }
        else if (n == 0)
        {
            buffer.resize(sum);
            return sum;
        }
        // buffer.size() always >= sum
        sum += n;
        curr += n;
        readablesize = buffer.size() - curr;
        if(readablesize < buffer.size()/2)
        {
            buffer.resize(buffer.size() * 2);
            readablesize = buffer.size() - curr;
        }
    }
    buffer.resize(sum);
    return sum;
}

int Socket::sendmessage(int fd, Buffer &buffer)
{
    int nleft = buffer.size();
    int curr = 0;
    int n = 0;
    while (nleft > 0)
    {
        if ((n = ::write(fd, &buffer[curr], nleft)) < 0)
        {
            int savedErrno = errno;
            if (savedErrno == EAGAIN || savedErrno == EWOULDBLOCK)
            {
                break;
            }
            else if (savedErrno == EINTR)
            {
                continue;
            }
        }
        else if (n == 0)
        {
            break;
        }
        nleft -= n;
        curr += n;
    }
    return curr;
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

char * Socket::getPeerInfo(int fd)
{
    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    socklen_t len = sizeof(addr);
    getpeername(fd, (sockaddr *) &addr, &len);
    return inet_ntoa(addr.sin_addr);
}