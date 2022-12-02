#include "Logger.h"
#pragma once

class LoggerPool{
    std::vector<Logger*> logarr;
public:
    LoggerPool() = default;
    void setPool(std::vector<Logger*> logarr);
    void printLog(Message* msg);
    std::vector<Logger*> getPool();
    ~LoggerPool();
};