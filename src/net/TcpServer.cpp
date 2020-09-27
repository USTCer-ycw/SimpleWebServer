//
// Created by yaochuanwang on 9/26/20.
//

#include "TcpServer.h"

using namespace SimpleServer;

TcpServer::TcpServer(EventLoop *loop, int port) : Server(loop,port)
{
    setReadCallBack(readCallBack_);
}

void TcpServer::setReadCallBack(const readCallBack &readCallBack)
{
    readCallBack_ = readCallBack;
}