//
// Created by 姚传望 on 2020/10/20.
//

#ifndef SIMPLEWEBSERVER_CONDITION_H
#define SIMPLEWEBSERVER_CONDITION_H

#include "src/base/noncopyable.h"
#include "src/base/MutexLock.h"
#include <condition_variable>

namespace SimpleServer
{
    class Condition : private noncopyable
    {
    public:
        explicit Condition(MutexLock& locker) : locker_(locker){}
        ~Condition() = default;

    public:
        void wait(){ cond_.wait(locker_.get()); }
        void notifyOne() { cond_.notify_one(); }
        void notifyAll() { cond_.notify_all(); }
        bool waitForSeconds(int seconds){ return cond_.wait_for(locker_.get(),std::chrono::seconds(1)) == std::cv_status::timeout; }
    private:
        MutexLock& locker_;
        std::condition_variable cond_;
    };
}

#endif //SIMPLEWEBSERVER_CONDITION_H
