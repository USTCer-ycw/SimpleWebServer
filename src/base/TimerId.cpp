//
// Created by 姚传望 on 2020/10/14.
//

#include "src/base/TimerId.h"
#include "src/base/Timer.h"
#include <sys/time.h>
#include <ctime>

using namespace SimpleServer::Time;

TimeStamp TimeStamp::now()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    int64_t seconds = tv.tv_sec;
    mircosecond sec = seconds * mircoPerSeconds + tv.tv_usec;
    return TimeStamp(sec);
}

TimerId::TimerId() :
seq_(0)
{
}

TimerId::TimerId(Timer* ptr, int64_t seq) :
timer_(ptr),
seq_(seq)
{
}