#include <iostream>
#include "src/net/EventLoop.h"
#include "src/net/Server.h"
#include "src/net/TcpServer.h"
#include "src/net/Client.h"
#include "src/net/Channel.h"

//#include <arpa/inet.h>
//#include <netinet/in.h>
//#include <sys/fcntl.h>
//#include <memory.h>
#include <unistd.h>
#include <src/net/Connection.h>

#include "src/net/Socket.h"
using namespace SimpleServer;
using namespace std;

void readback(char* buf)
{
   printf("recved:%s\n",buf);
}

void onMessage(Channel* ch)
{
//    printf("ready sleep\n");
//    ::sleep(5);
    printf("getInpput:%s", ch->getInput().data());

    ch->send(ch->getInput());
}

void onConnect(const ConnectionPtr &connection)
{
    cout << connection->getPeer() << endl;
//    connection->shutdownWR();
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

void testServer()
{
    EventLoop loop;
    Server server(&loop,2000);
//    server.setReadMsgCallBack(std::bind(readback,std::placeholders::_1));
    server.setOnConnect(std::bind(onConnect, std::placeholders::_1));
    server.start();
    loop.loop();
}

void testClient()
{
    EventLoop loop;
    Client cli(&loop,"127.0.0.1",2000);
    cli.setReadCallBack(std::bind(readback,std::placeholders::_1));
    cli.connect();
    loop.loop();
}
#include <memory.h>
int main()
{
    printf("%s  line %d\n", __FILE__, __LINE__);
    testServer();
    Socket::Buffer buffer;
    buffer.reserve(128);
    buffer.resize(128);
    char* str = "test";
    memcpy(buffer.data(), str, strlen(str));
    char* ptr = buffer.data();
    printf("%x\n", buffer.data());
    buffer.resize(strlen(str));
//    ptr = buffer.data();
    printf("%x\n", buffer.data());
//    buffer.reserve(buffer.capacity() * 2);
    cout << buffer.size() << " " << buffer.capacity() << endl;
    for (int i = 0; i < strlen(str); i++)
    {
        cout << buffer[i];
    }
//    testServer();
//    testClient();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
