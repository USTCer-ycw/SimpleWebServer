#include <iostream>
#include "src/net/EventLoop.h"
#include "src/net/Server.h"
using namespace SimpleServer;
int main()
{
    EventLoop loop;
    Server server(&loop,2000);
    loop.loop();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
