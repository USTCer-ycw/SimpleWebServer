//
// Created by 姚传望 on 2020/10/14.
//

#ifndef SIMPLEWEBSERVER_LOGSTREAM_H
#define SIMPLEWEBSERVER_LOGSTREAM_H

#include "src/base/noncopyable.h"
#include <string>
#include <memory.h>

namespace SimpleServer
{
    const int kSmallBuffer = 4000;
    const int kLargeBuffer = kSmallBuffer * 1000;

    template <int SIZE>
    class FixedBuffer : private noncopyable
    {
    public:
        FixedBuffer() : cur_(data_){}
        ~FixedBuffer() = default;

    public:
        void append(const char *msg, size_t len)
        {
            if(availablespace() >= len)
            {
                memcpy(cur_, msg, len);
                cur_ += len;
            }
        }
        const char *data() const { return data_; }
        int length() const { return static_cast<int>(cur_ - data_); }
        char* current() { return cur_; }
        size_t availablespace() { return static_cast<size_t>(end() - cur_); }
        void add(size_t len) { cur_ += len; }
        void reset() { cur_ = data_; }
        void bzero() { memset(data_, 0, sizeof(data_)); }
    private:
        const char* end() const { return data_ + sizeof(data_); }
        char data_[SIZE];
        char *cur_;
    };

    class LogStream : private noncopyable
    {
    public:
        using Buffer = FixedBuffer<kSmallBuffer>;
    public:
        LogStream& operator<<(bool v)
        {
            buffer_.append(v ? "1" : "0", 1);
            return *this;
        }
        LogStream& operator<<(short);
        LogStream& operator<<(unsigned short);
        LogStream& operator<<(int);
        LogStream& operator<<(unsigned int);
        LogStream& operator<<(long);
        LogStream& operator<<(unsigned long);
        LogStream& operator<<(long long);
        LogStream& operator<<(unsigned long long);
        LogStream& operator<<(const void*);
        LogStream& operator<<(float v) {
            *this << static_cast<double>(v);
            return *this;
        }
        LogStream& operator<<(double);
        LogStream& operator<<(long double);
        LogStream& operator<<(char c)
        {
            buffer_.append(&c,1);
            return *this;
        }
        LogStream& operator<<(const char* msg)
        {
            if(msg)
                buffer_.append(msg, strlen(msg));
            else
                buffer_.append("(null)", 6);
            return *this;
        }
        LogStream& operator<<(const unsigned char* str) {
            return operator<<(reinterpret_cast<const char*>(str));
        }

        LogStream& operator<<(const std::string& v) {
            buffer_.append(v.c_str(), v.size());
            return *this;
        }

    public:
        void append(const char* data,size_t len) { buffer_.append(data, len); }
        const Buffer& buffer() const { return buffer_; }
        void resetBuffer() { buffer_.reset(); }
    private:
        void staticCheck();

        template<typename T>
        void formatInteger(T v);
        Buffer buffer_;
        static const int kMaxNumerSize = 32;
    };
}

#endif //SIMPLEWEBSERVER_LOGSTREAM_H
