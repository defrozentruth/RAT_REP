#include "../Message/Message.h"
#pragma once

class Logger{
public:
    virtual void print(Message* msg) = 0;
    virtual ~Logger() = default;
};