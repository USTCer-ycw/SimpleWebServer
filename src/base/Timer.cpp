//
// Created by 姚传望 on 2020/10/15.
//

#include "src/base/Timer.h"

using namespace SimpleServer::Time;

std::atomic_int Timer::seq_(0);

void Timer::restart(TimeStamp now)
{
    if (repeat_)
    {
        expirationtime_ = addTime(now, interval_);
    }
    else
    {
        expirationtime_ = 0;
    }
}
