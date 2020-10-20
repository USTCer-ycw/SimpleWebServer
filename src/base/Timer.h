//
// Created by 姚传望 on 2020/10/15.
//

#ifndef SIMPLEWEBSERVER_TIMER_H
#define SIMPLEWEBSERVER_TIMER_H
#include "src/net/Socket.h"
#include "src/base/TimerId.h"
#include <atomic>
namespace SimpleServer
{
    namespace Time
    {
        class Timer
        {
        public:
            Timer(TimerCB cb,TimeStamp when,double interval) :
                timerCB_(cb), expirationtime_(when),interval_(interval),repeat_(interval > 0.0){ ++seq_; }
            ~Timer() = default;

        public:
            void runExpirEvent()
            {
                if (timerCB_)
                {
                    printf("timerCB_ not Null\n");
                    timerCB_();
                }
                else
                {
                    printf("unset\n");
                }
            }
            int sequence() const { return seq_; }
            TimeStamp getExpirTime() const { return expirationtime_; }
            bool repeat() const { return repeat_; }
            void restart(TimeStamp now);
        private:
            TimerCB timerCB_;
            TimeStamp expirationtime_;
            double interval_;
            bool repeat_;
            static std::atomic_int seq_;
        };

    }
}

#endif //SIMPLEWEBSERVER_TIMER_H
