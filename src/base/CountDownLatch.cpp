//
// Created by 姚传望 on 2020/10/20.
//

#include "src/base/CountDownLatch.h"
#include "src/base/Logging.h"
using namespace SimpleServer;

CountDownLatch::CountDownLatch(int count) :
locker_(),
cond_(locker_),
count_(count)
{
    LOG << (locker_.islock() ? "already lock!" : "unlock");
}

void CountDownLatch::wait()
{
    MutexLockGuard lock(locker_);
    while (count_ > 0)
    {
        cond_.wait();
    }
}

void CountDownLatch::countDown()
{
    MutexLockGuard lock(locker_);
    --count_;
    if (count_ == 0)
    {
        cond_.notifyAll();
    }
}
