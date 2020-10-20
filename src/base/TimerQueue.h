//
// Created by 姚传望 on 2020/10/15.
//

#ifndef SIMPLEWEBSERVER_TIMERQUEUE_H
#define SIMPLEWEBSERVER_TIMERQUEUE_H

#include "src/base/Timer.h"
#include "src/net/Channel.h"
#include <set>
namespace SimpleServer
{
    class EventLoop;
    namespace Time
    {
        class TimerQueue
        {
        public:
            TimerQueue(EventLoop *loop);
            ~TimerQueue() = default;

        public:
            TimerId addTimer(TimerCB cb, TimeStamp when, double interval);
            void cancel(TimerId timerId);

        private:
            using Entry = std::pair<TimeStamp,Timer*>;
            using TimerList = std::set<Entry>;
            using ActiveTimer = std::pair<Timer*, int64_t>;
            using ActiveTimerSet = std::set<ActiveTimer>;
        private:
            void addTimerToLoop(Timer* timer);
            void cancelTimerInLoop(TimerId timerId);
            void handleRead();
            std::vector<Entry> getExpired(TimeStamp now);
            void reset(const std::vector<Entry> &expired, TimeStamp now);
            bool insert(Timer *timer);
        private:
            const int timerfd_;
            EventLoop* loop_;
            Channel timerChannel_;
            TimerList timerList_;
            ActiveTimerSet activeTimers_;
            ActiveTimerSet cancelTimers_;
        };
    }
}

#endif //SIMPLEWEBSERVER_TIMERQUEUE_H
