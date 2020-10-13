//
// Created by yaochuanwang on 10/13/20.
//

#ifndef SIMPLEWEBSERVER_LOGFILE_H
#define SIMPLEWEBSERVER_LOGFILE_H

#include "src/base/noncopyable.h"
#include "src/base/FileUtil.h"
#include <memory>
namespace SimpleServer
{
    class LogFile : private noncopyable
    {
    public:
        LogFile(const std::string &filename,int EveryNflush = 1024);
        ~LogFile();

    public:
        //FIXME unsafe
        void append(const char* msg,size_t len);
        void flush();

    private:
        const std::string filename_;
        const int everyNfluse_;
        int count_;
        std::unique_ptr<AppendFile> filePtr_;
    };
}

#endif //SIMPLEWEBSERVER_LOGFILE_H
