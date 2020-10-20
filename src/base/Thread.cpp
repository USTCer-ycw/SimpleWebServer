//
// Created by 姚传望 on 2020/10/20.
//

#include "src/base/Thread.h"
#include "src/base/CurrentThread.h"
#include "src/base/Logging.h"
#include <sys/prctl.h>
#include <unistd.h>
#include <syscall.h>
namespace SimpleServer
{
    namespace CurrentThread
    {
        __thread int t_cachedTid = 0;
        __thread char t_tidString[32];
        __thread int t_tidStringLength = 6;
        __thread const char *t_threadName = "default";
    }
}


pid_t gettid()
{
    pid_t t = static_cast<pid_t>(::syscall(SYS_gettid));
    printf("gettid:%d,getpid:%d\n", t, getpid());
    return t;
}

void SimpleServer::CurrentThread::cacheTid()
{
    if (t_cachedTid == 0)
    {
        t_cachedTid = gettid();
        t_tidStringLength = snprintf(t_tidString, sizeof(t_tidString), "%5d", t_cachedTid);
    }
}

struct ThreadData
{
    using ThreadFunc = SimpleServer::Thread::ThreadFunc;
    using CountDownLatch =  SimpleServer::CountDownLatch;
    ThreadFunc func_;
    std::string name_;
    pid_t* tid_;
    CountDownLatch* latch_;
    ThreadData(const ThreadFunc& func,const std::string& name,pid_t* tid,CountDownLatch* latch):
    func_(func),name_(name),tid_(tid),latch_(latch)
    {}

    void runInThread()
    {
        *tid_ = SimpleServer::CurrentThread::tid();
        tid_ = NULL;
        latch_->countDown();
        latch_ = NULL;

        SimpleServer::CurrentThread::t_threadName = name_.empty() ? "Thread" : name_.c_str();
        prctl(PR_SET_NAME, SimpleServer::CurrentThread::t_threadName);

        func_();
        SimpleServer::CurrentThread::t_threadName = "finished";
    }
};

SimpleServer::Thread::Thread(const ThreadFunc &func, const std::string &name):
started_(false),
joined_(false),
thread_(),
id_(0),
func_(func),
name_(name),
latch_(1)
{
}

SimpleServer::Thread::~Thread()
{
    if(started_ && !joined_)
    {
//        thread_.detach();
    }
}

void* startThread(void* obj)
{
    ThreadData* data = static_cast<ThreadData*>(obj);
    data->runInThread();
    delete data;
    return NULL;
}

void test_(SimpleServer::CountDownLatch* ptr)
{
    printf("test\n");
//    ptr->countDown();
}

void SimpleServer::Thread::start()
{
    started_ = true;
    ThreadData *data = new ThreadData(func_, name_, &tid_, &latch_);
//    data->runInThread();
    std::thread th(test_,&latch_);
//    startThread((void*)data);
//    thread_ = std::thread(startThread, data);
    latch_.wait();
}

void SimpleServer::Thread::join()
{
    LOG << "try join" << (started_ ? "srated" : "unstarted") << "," << (joined_ ? "joined" : "unjoined");
    joined_ = true;
    thread_.join();
}
