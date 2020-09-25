//
// Created by yaochuanwang on 9/24/20.
//

#ifndef SIMPLEWEBSERVER_NONCOPYABLE_H
#define SIMPLEWEBSERVER_NONCOPYABLE_H

class noncopyable
{
public:
    noncopyable() = default;
    ~noncopyable() = default;

public:
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
};

#endif //SIMPLEWEBSERVER_NONCOPYABLE_H
