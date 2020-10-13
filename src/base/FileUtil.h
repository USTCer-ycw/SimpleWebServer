//
// Created by yaochuanwang on 10/13/20.
//

#ifndef SIMPLEWEBSERVER_FILEUTIL_H
#define SIMPLEWEBSERVER_FILEUTIL_H

#include "src/base/noncopyable.h"
#include <string>
namespace SimpleServer
{
    class AppendFile : private noncopyable
    {
    public:
        explicit AppendFile(const char *filename);
        ~AppendFile();

    public:
        void append(const char *msg, size_t len);
        void flush();
        size_t write(const char *msg, size_t len);
    private:
        const char* filename_;
        FILE* fp_;
        char buffer_[64 * 1024];
    };
}

#endif //SIMPLEWEBSERVER_FILEUTIL_H
