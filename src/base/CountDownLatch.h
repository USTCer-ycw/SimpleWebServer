//
// Created by 姚传望 on 2020/10/20.
//

#ifndef SIMPLEWEBSERVER_COUNTDOWNLATCH_H
#define SIMPLEWEBSERVER_COUNTDOWNLATCH_H

#include "src/base/Condition.h"
#include "src/base/MutexLock.h"
#include "src/base/noncopyable.h"

namespace SimpleServer
{
    class CountDownLatch : private noncopyable
    {
    public:
        explicit CountDownLatch(int count);
        void wait();
        void countDown();

    private:
        mutable MutexLock locker_;
        Condition cond_;
        int count_;
    };
}

#endif //SIMPLEWEBSERVER_COUNTDOWNLATCH_H
