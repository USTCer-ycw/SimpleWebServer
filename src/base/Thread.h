//
// Created by 姚传望 on 2020/10/20.
//

#ifndef SIMPLEWEBSERVER_THREAD_H
#define SIMPLEWEBSERVER_THREAD_H

#include "src/base/noncopyable.h"
#include "src/base/CountDownLatch.h"
#include <thread>
#include <memory>
#include <functional>
namespace SimpleServer
{
    class Thread : noncopyable
    {
    public:
        using ThreadFunc = std::function<void()>;
        using ThreadID = std::thread::id;
    public:
        explicit Thread(const ThreadFunc &func, const std::string &name = "Thread");
        ~Thread();

    public:
        void start();
        void join();
        bool started() const { return started_;}
        pid_t gettid() const { return tid_; }
        const std::string name() const { return name_; }

    private:
        bool started_;
        bool joined_;
        std::thread thread_;
        ThreadID id_;
        pid_t tid_;
        ThreadFunc func_;
        std::string name_;
        CountDownLatch latch_;
    };
}

#endif //SIMPLEWEBSERVER_THREAD_H
