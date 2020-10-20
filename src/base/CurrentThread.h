//
// Created by 姚传望 on 2020/10/20.
//

#ifndef SIMPLEWEBSERVER_CURRENTTHREAD_H
#define SIMPLEWEBSERVER_CURRENTTHREAD_H

#include <stdint.h>

namespace SimpleServer
{
    namespace CurrentThread
    {
        extern __thread int t_cachedTid;
        extern __thread char t_tidString[32];
        extern __thread int t_tidStringLength;
        extern __thread const char *t_threadName;
        void cacheTid();
        inline int tid()
        {
//            if (__builtin_expect(t_cachedTid == 0, 0))
//            {
//                cacheTid();
//            }
            if (t_cachedTid == 0)
            {
                cacheTid();
            }
            return t_cachedTid;
        }
        inline const char *tidString()
        {
            return t_tidString;
        }
        inline int tidStringLength()
        {
            return t_tidStringLength;
        }
        inline const char* name()
        {
            return t_threadName;
        }
    }
}

#endif //SIMPLEWEBSERVER_CURRENTTHREAD_H
