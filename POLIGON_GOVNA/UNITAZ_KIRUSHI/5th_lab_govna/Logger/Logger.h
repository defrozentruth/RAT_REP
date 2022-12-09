#include "../Message/Message.h"
#include <vector>
#pragma once

class Logger{
public:
    virtual void print(Message* msg) = 0;
    virtual ~Logger() = default;
};