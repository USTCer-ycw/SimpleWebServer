//
// Created by 姚传望 on 2020/10/14.
//

#include "src/base/Logging.h"
#include <sys/time.h>

using namespace SimpleServer;

void defaultoutput(const char *msg, int len)
{
    ::fwrite(msg, len, 1, stdout);
}

Logger::Logger(const char *filename, int line) :
impl_(filename,line)
{
}

Logger::Impl::Impl(const char *filename, int line) :
stream_(),
filename_(filename),
line_(line)
{
    formatTime();
}

void Logger::Impl::formatTime()
{
    struct timeval tv;
    time_t time;
    char str_t[26] = {0};
    gettimeofday(&tv, NULL);
    time = tv.tv_sec;
    struct tm* p_time = localtime(&time);
    strftime(str_t, 26, "%Y-%m-%d %H:%M:%S ", p_time);
    stream_ << str_t;
}

Logger::~Logger()
{
    impl_.stream_ << " -- " << impl_.filename_ << ":" << impl_.line_ << '\n';
    defaultoutput(stream().buffer().data(), stream().buffer().length());
}