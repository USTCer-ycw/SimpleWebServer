//
// Created by yaochuanwang on 10/13/20.
//

#include "src/base/FileUtil.h"

using namespace SimpleServer;

AppendFile::AppendFile(const char *filename) :
filename_(filename),
fp_(fopen(filename_,"ae"))
{
    // e means close_exec on sub_thread
    ::setbuffer(fp_, buffer_, sizeof(buffer_));
}
AppendFile::~AppendFile()
{
    fclose(fp_);
}

void AppendFile::append(const char *msg, size_t len)
{
    size_t n = 0, nleft = len;
    size_t nwrite = 0;
    while (nleft > 0)
    {
        if ((n = this->write(msg + nwrite, nleft)) > 0)
        {
            nleft -= n;
            nwrite += n;
        }
        else if (n == 0)
        {
            int error = ferror(fp_);
            if (error)
            {
                fprintf(stderr, "%s,%d:append error", __FILE__, __LINE__);
            }
            break;
        }
    }
}

void AppendFile::flush()
{
    ::fflush_unlocked(fp_);
}

size_t AppendFile::write(const char *msg, size_t len)
{
    return ::fwrite_unlocked(msg, 1, len, fp_);
}
