//
// Created by yaochuanwang on 9/29/20.
//

#include "src/net/Client.h"
#include "src/net/Socket.h"
#include <memory.h>

using namespace SimpleServer;

Client::Client(string ip, int port) :
ip_(ip),
port_(port)
{
    fd_ = Socket::CreateNonBlockFd();

    memset(&clientaddr_,0,sizeof(clientaddr_));
    clientaddr_.sin_family = AF_INET;
    clientaddr_.sin_addr.s_addr = inet_addr(ip.c_str());
    clientaddr_.sin_port = htons(port);

    Socket::Bind(&clientaddr_);
}

int Client::connect()
{
    Socket::Connect(fd_,&clientaddr_);
}

void Client::sendStr(const string &msg)
{
    Socket::sendmsg(fd_,msg.c_str());
}
