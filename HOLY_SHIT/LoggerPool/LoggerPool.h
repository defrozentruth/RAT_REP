#include "../Logger/Logger.h"
#pragma once

class LoggerPool{
    Logger** logarr;
public:
    LoggerPool() = default;
    void setPool(Logger** logarr);
    void printLog(Message* msg);
    ~LoggerPool();
};