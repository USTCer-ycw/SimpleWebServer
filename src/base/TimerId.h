//
// Created by 姚传望 on 2020/10/14.
//

#ifndef SIMPLEWEBSERVER_TIMERID_H
#define SIMPLEWEBSERVER_TIMERID_H

#include "src/base/noncopyable.h"
#include "src/net/Socket.h"
#include <cstdint>
#include <stdio.h>
#include <math.h>
namespace SimpleServer
{
    namespace Time
    {
        class Timer;
        using mircosecond = uint64_t;
        class TimeStamp
        {
        public:
            TimeStamp() : sinceepoch_(0) {}
            TimeStamp(mircosecond seconds) : sinceepoch_(seconds) {}
            ~TimeStamp() = default;
        public:
            mircosecond sinceepoch() const { return sinceepoch_; }
            static TimeStamp now();
            static const uint32_t mircoPerSeconds = 1000 * 1000;
        private:
            mircosecond sinceepoch_;
        };

        inline TimeStamp addTime(TimeStamp timeStamp,double seconds)
        {
            int64_t delta = static_cast<int64_t>(seconds*TimeStamp::mircoPerSeconds);
            return TimeStamp(timeStamp.sinceepoch() + delta);
        }
        inline bool operator<(TimeStamp lhs,TimeStamp rhs)
        {
            return lhs.sinceepoch() < rhs.sinceepoch();
        }

        inline bool operator==(TimeStamp lhs, TimeStamp rhs)
        {
            return lhs.sinceepoch() == rhs.sinceepoch();
        }

        class TimerId
        {
        public:
            TimerId();
            TimerId(Timer* ptr,int64_t seq);
            ~TimerId() = default;
        private:
            Timer* timer_;
            int64_t seq_;
        };

        inline double timedifference(TimeStamp& high,TimeStamp& low)
        {
            int64_t h = high.sinceepoch();
            int64_t l = low.sinceepoch();
            return (static_cast<double>(abs(h - l)) / TimeStamp::mircoPerSeconds);
        }
    }

}

#endif //SIMPLEWEBSERVER_TIMERID_H
