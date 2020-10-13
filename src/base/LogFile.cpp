//
// Created by yaochuanwang on 10/13/20.
//

#include "src/base/LogFile.h"

using namespace SimpleServer;

LogFile::LogFile(const std::string &filename, int EveryNflush) :
filename_(filename),
everyNfluse_(EveryNflush),
count_(0)
{
    filePtr_.reset(new AppendFile(filename_.c_str()));
}

void LogFile::append(const char* msg,size_t len)
{
    filePtr_->append(msg, len);
    if (++count_ >= 1024)
    {
        this->flush();
        count_ = 0;
    }
}

void LogFile::flush()
{
    filePtr_->flush();
}