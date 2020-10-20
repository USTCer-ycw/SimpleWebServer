//
// Created by 姚传望 on 2020/10/20.
//

#ifndef SIMPLEWEBSERVER_MUTEXLOCK_H
#define SIMPLEWEBSERVER_MUTEXLOCK_H

#include "src/base/noncopyable.h"
#include <mutex>
namespace SimpleServer
{
    class MutexLock : private noncopyable
    {
    public:
        MutexLock() : lock_(mutex_,std::defer_lock){}
        ~MutexLock()  = default;
    public:
        void lock() { lock_.lock(); }
        void unlock() { lock_.unlock();}
        bool islock() { return lock_.owns_lock(); }
    private:
        using mutex_type = std::unique_lock<std::mutex>::mutex_type;
        std::mutex mutex_;
        std::unique_lock<std::mutex> lock_;
    public:
        std::unique_lock<std::mutex>& get(){ return lock_; }
    private:
//        friend class Condition;
    };

    class MutexLockGuard : private noncopyable
    {
    public:
        explicit MutexLockGuard(MutexLock& locker) : locker_(locker){ locker_.lock(); }
        ~MutexLockGuard(){ locker_.unlock(); }
    private:
        MutexLock& locker_;
    };
}

#endif //SIMPLEWEBSERVER_MUTEXLOCK_H
