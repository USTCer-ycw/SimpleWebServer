//
// Created by yaochuanwang on 9/29/20.
//

#ifndef SIMPLEWEBSERVER_CLIENT_H
#define SIMPLEWEBSERVER_CLIENT_H

#include <string>
#include <arpa/inet.h>
using std::string;
namespace SimpleServer
{
    class Client
    {
    public:
        Client(string ip,int port);
        ~Client() = default;

    public:
        void sendStr(const string& msg);
        void sendBinStr(const string& msg);
        int connect();
    private:
        int fd_;
        int port_;
        string ip_;
        struct sockaddr_in clientaddr_;
    };
}

#endif //SIMPLEWEBSERVER_CLIENT_H
