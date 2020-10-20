//
// Created by yaochuanwang on 9/25/20.
//

#include "src/net/Server.h"
#include "src/net/Socket.h"
#include "src/net/Channel.h"
#include "src/net/EventLoop.h"
#include "src/net/Connection.h"
using namespace SimpleServer;

Server::Server(EventLoop *loop, int port):
loop_(loop),
acceptChannel_(new Channel(loop,Socket::CreateNonBlockFd())),
acceptfd_(acceptChannel_->getSockfd())
{
    Socket::BindAndListen(acceptChannel_->getSockfd(),port);
    acceptChannel_->sethandleRead(std::bind(&Server::handleNewConn, this));
    acceptChannel_->setEvent(EPOLLIN | EPOLLET);
}

void Server::start()
{
    using std::placeholders::_1;
//    acceptChannel_->sethandleRead(std::bind(&Server::handleNewConn, this));
//    acceptChannel_->setConnNewBack(std::bind(&Server::handleNewConn,this,_1));
//    acceptChannel_->setReadMsgBack(std::bind(&Server::handleReadMsg,this,_1));
    loop_->addChannelToPoller(acceptChannel_);
}

void Server::handleRead()
{
    char message[64];
    int fd = acceptChannel_->getSockfd();
    int n = Socket::readmessage(fd,message);
    printf("%s  line %d\n", __FILE__, __LINE__);
    printf("read %d bytes, %s\n",n,message);
}

void Server::handleReadMsg(char* buf)
{
//    if(readCallBack_)
//        readMsgCallBack_(buf);
}

void Server::handleConn()
{

//    if(connCallBack_)
//        connCallBack_();
//    else
//    {
//       printf("new conn\n");
//    }

//    channel->setSockfd(Socket::acceptSocket())
//    channel->setReadMsgBack(std::bind())
}

void Server::handleNewConn()
{
    int acceptfd = 0;
    while ((acceptfd = Socket::acceptSocket(acceptfd_)) > 0)
    {
        ConnectionPtr accPtr = std::make_shared<Connection>(loop_, acceptfd);
        accPtr->setOnConnectCB(connectBack_);
        accPtr->setOnMessageCB(messageBack_);
        Socket::setNonBlock(acceptfd);
        connectionMap_[acceptfd] = accPtr;
        connectBack_(accPtr);
    }

//    Channel* channel = new Channel(loop_);
//    channel->setSockfd(Socket::acceptSocket(acceptfd));
//    Socket::setNonBlock(channel->getSockfd());
//    channel->setReadMsgBack(std::bind(&Server::handleReadMsg,this,std::placeholders::_1));
//    channel->setmsgCallBack(msgCallBack_);
//    channel->setEvent(EPOLLIN | EPOLLET);
//    loop_->addChannelToPoller(channel);
}

void Server::defaultMeeageCB(const ConnectionPtr &conn)
{
    printf("recv : %s\n", conn->getInput().data());
}

void Server::defaultConnectCB(const ConnectionPtr &conn)
{

}
