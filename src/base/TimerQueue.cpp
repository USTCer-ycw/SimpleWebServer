//
// Created by 姚传望 on 2020/10/15.
//

#include "src/base/TimerQueue.h"
#include "src/net/EventLoop.h"
#include "src/base/Logging.h"
#include <sys/timerfd.h>
#include <unistd.h>
using namespace SimpleServer::Time;
using namespace SimpleServer;

int createTImerfd()
{
    int timerfd = ::timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC);
    if(timerfd < 0)
    {
        LOG << "create Timerfd error";
        return -1;
    }
    LOG << "create timerfd:" << timerfd;
    return timerfd;
}

struct timespec howMuchTimeFromNow(TimeStamp when)
{
    mircosecond mirsecs  = when.sinceepoch() - TimeStamp::now().sinceepoch();
    if(mirsecs < 100) // 小于100us
    {
        mirsecs = 100;
    }
    timespec tv;
    tv.tv_sec = static_cast<time_t>(mirsecs / TimeStamp::mircoPerSeconds);
    tv.tv_nsec = static_cast<long>((mirsecs % TimeStamp::mircoPerSeconds) * 1000);
    return tv;
}

void readTimerfd(int timerfd, TimeStamp now)
{
    uint64_t howmany;
    ssize_t n = ::read(timerfd, &howmany, sizeof(howmany));
    LOG << "read Timerfd";
}

void resetTimerfd(int timerfd, TimeStamp expiration)
{
    struct itimerspec newtime;
    struct itimerspec oldtime;
    bzero(&newtime, sizeof(itimerspec));
    bzero(&oldtime, sizeof(itimerspec));
    newtime.it_value = howMuchTimeFromNow(expiration);
    int ret = ::timerfd_settime(timerfd, 0, &newtime, &oldtime);
    if (ret != 0)
    {
        perror("error");
        LOG << "settime error";
    }
//    struct itimerspec its;
//    int ms = 1000;
//    int timerFd = timerfd;
//    its.it_interval.tv_sec = 2; // 2 seconds
//    its.it_interval.tv_nsec = 0;
//    its.it_value.tv_sec = ms / 1000;
//    its.it_value.tv_nsec = (ms % 1000) * 1000 * 1000;
//    if (timerfd_settime(timerFd, 0, &its, NULL) < 0)
//    {
//        perror("settime error");
//    }
////        return -1;
//    printf("timer update: %d\n", ms);

}

TimerQueue::TimerQueue(EventLoop *loop) :
loop_(loop),
timerfd_(createTImerfd()),
timerChannel_(loop,timerfd_),
timerList_()
{
    int size = timerList_.size();
    timerChannel_.sethandleRead(std::bind(&TimerQueue::handleRead, this));
    timerChannel_.setEvent(EPOLLIN);
    loop_->addChannelToPoller(&timerChannel_);
}

TimerId TimerQueue::addTimer(TimerCB cb, TimeStamp when, double interval)
{
    Timer* timer(new Timer(cb, when, interval));
    bool earliestChanged = insert(timer);
    if(earliestChanged)
    {
        resetTimerfd(timerfd_, timer->getExpirTime());
    }
    return TimerId(timer, timer->sequence());
}

bool TimerQueue::insert(Timer *timer)
{
    bool earliestChanged = false;
    TimeStamp when = timer->getExpirTime();
    TimerList::iterator it = timerList_.begin();
    if (it == timerList_.end() || when < it->first)
    {
        earliestChanged = true;
    }
    {
        timerList_.insert(Entry(when, timer));
    }
    {
        activeTimers_.insert(ActiveTimer(timer, timer->sequence()));
    }
    return earliestChanged;
}

void TimerQueue::handleRead()
{
//    Timer* ptr = timerList_.begin()->second;
//    ptr->runExpirEvent();
//    LOG << "test cb_(),---";
    TimeStamp now(TimeStamp::now());
//    readTimerfd(timerfd_, now);
    std::vector<Entry> expired = getExpired(now);
    for (const Entry &it : expired)
    {
        it.second->runExpirEvent();
    }
    reset(expired, now);
}

std::vector<TimerQueue::Entry> TimerQueue::getExpired(TimeStamp now)
{
    std::vector<Entry> expired;
    Entry sentry(now, reinterpret_cast<Timer *>(UINTPTR_MAX));
    TimerList::iterator end = timerList_.lower_bound(sentry);
    std::copy(timerList_.begin(), end, std::back_inserter(expired));
    LOG << expired.size() << "个过期事件";
    timerList_.erase(timerList_.begin(), end);
    for (const Entry &it : expired)
    {
        ActiveTimer timer(it.second, it.second->sequence());
        activeTimers_.erase(timer);
    }
    return expired;
}


void TimerQueue::reset(const std::vector<Entry> &expired, TimeStamp now)
{
    TimeStamp nextExpire;
    for (const Entry &it:expired)
    {
        ActiveTimer timer(it.second, it.second->sequence());
        if (it.second->repeat() && cancelTimers_.find(timer) == cancelTimers_.end())
        {
            it.second->restart(now);
            insert(it.second);
        }
        else
        {
            delete it.second;
        }
    }
    if (!timerList_.empty())
    {
        nextExpire = timerList_.begin()->second->getExpirTime();
    }
    if (nextExpire.sinceepoch() > 0)
    {
        resetTimerfd(timerfd_, nextExpire);
    }
}