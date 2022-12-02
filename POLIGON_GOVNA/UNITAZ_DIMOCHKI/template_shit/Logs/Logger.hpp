#include "Message.hpp"
#pragma once

class Logger{
public:
    virtual void output(Message* msg) = 0;
};