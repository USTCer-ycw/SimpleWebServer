#include <iostream>
#include "src/net/EventLoop.h"
#include "src/net/Server.h"
#include "src/net/TcpServer.h"

//#include <arpa/inet.h>
//#include <netinet/in.h>
//#include <sys/fcntl.h>
//#include <memory.h>

#include "src/net/Socket.h"
using namespace SimpleServer;

void readback(char* buf)
{
   printf("recved:%s\n",buf);
}

void test()
{
//    sockaddr_in server;
//    memset(&server,0,sizeof(server));
//    server.sin_port = htons(2000);
//    server.sin_addr.s_addr = INADDR_ANY;
//    server.sin_family = AF_INET;
//
//    int sockfd = ::socket(AF_INET,SOCK_STREAM,0);
//    int oldfd = ::fcntl(sockfd,F_GETFL,0);
//    oldfd |= O_NONBLOCK;
//    int ret = ::fcntl(sockfd,F_SETFL,oldfd);
//
//    bind(sockfd,(sockaddr*)&server,static_cast<socklen_t>(sizeof(server)));
//    listen(sockfd,SOMAXCONN);
//    accept()
    int sockfd = Socket::CreateNonBlockFd();
    Socket::BindAndListen(sockfd,2000);
    int ret = Socket::acceptSocket(sockfd);
    if(ret < 0)
    {
        printf("error\n");
        perror("accept");
    }
    char buf[64];
    Socket::setNonBlock(ret);
    Socket::readmessage(sockfd,buf);
}


int main()
{
//    test();
    EventLoop loop;
    Server server(&loop,2000);
    server.setReadMsgCallBack(std::bind(readback,std::placeholders::_1));
    server.start();
//    TcpServer server(&loop,2000);
//    server.setReadCallBack(std::bind(readback,std::placeholders::_1));
//    Server server(&loop,2000);
    loop.loop();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
