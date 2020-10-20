//
// Created by 姚传望 on 2020/10/14.
//

#ifndef SIMPLEWEBSERVER_LOGGING_H
#define SIMPLEWEBSERVER_LOGGING_H

#include "src/base/LogStream.h"

namespace SimpleServer
{
    class Logger
    {
    public:
        Logger(const char* filename,int line);
        ~Logger();

    public:
        LogStream& stream() { return impl_.stream_; }
    private:
        class Impl
        {
        public:
            Impl(const char *filename, int line);
            void formatTime();

        public:
            LogStream stream_;
            const char* filename_;
            int line_;
        };
        Impl impl_;
    };
#define LOG SimpleServer::Logger(__FILE__,__LINE__).stream()
}

#endif //SIMPLEWEBSERVER_LOGGING_H
