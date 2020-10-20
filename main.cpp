#include <iostream>
#include <src/net/EventLoop.h>
#include "src/net/Server.h"
#include "src/net/TcpServer.h"
#include "src/net/Client.h"
#include "src/net/Channel.h"

//#include <arpa/inet.h>
//#include <netinet/in.h>
//#include <sys/fcntl.h>
//#include <memory.h>
#include <unistd.h>
#include <set>
#include <src/net/Connection.h>

#include "src/net/Socket.h"
#include "src/base/FileUtil.h"
#include "src/base/LogStream.h"
#include "src/base/Logging.h"
#include "src/base/TimerId.h"
#include "src/base/TimerQueue.h"
#include "src/base/Thread.h"
using namespace SimpleServer;
using namespace std;

void readback(char* buf)
{
   printf("recved:%s\n",buf);
}

//void onMessage(Channel* ch)
//{
////    printf("ready sleep\n");
////    ::sleep(5);
//    printf("getInpput:%s", ch->getInput().data());
//
//    ch->send(ch->getInput());
//}

void onConnect(const ConnectionPtr &connection)
{
    cout << connection->getPeer() << endl;
//    connection->shutdownWR();
}

void onMessage(const ConnectionPtr& message)
{
    printf("receive:%s\n", message->getInput().data());
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
    server.setOnMessage(std::bind(onMessage, std::placeholders::_1));
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

void test_timer()
{
    EventLoop loop;
//    loop.runAt(1,std::bind(print_hello));
//    loop.runAfter(3, std::bind(print_hello));
    loop.runEvery(1, [](){
        printf("-------------hello-----------------\n");
    });
    loop.runEvery(1, [](){
        printf("-------------world-----------------\n");
    });
    loop.loop();
}

void hello()
{
    printf("hello\n");
}

void test_thread()
{
    std::function<void()> func = hello;
    Thread thread(func);
    thread.start();
//    std::mutex mtx;
//    unique_lock<std::mutex> lck(mtx);
//    cout << lck.owns_lock() << endl;
//    lck.lock();
}

int main()
{
//    AppendFile file("test.txt");
    test_thread();
    while(1){}
    test_timer();
    LOG << "ycw";
    LOG << "1234";
    printf("debug\n");
    printf("%s  line %d\n", __FILE__, __LINE__);
    testServer();
    Socket::Buffer buffer;
    buffer.reserve(128);
    buffer.resize(128);
    const char* str = "test";
    memcpy(buffer.data(), str, strlen(str));
    const char* ptr = buffer.data();
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
