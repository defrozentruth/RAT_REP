#include "../Message/ErrorMessage.h"
#include "../Logger/LoggerPool.h"
#include "LogType.h"
#pragma once

class ErrorLog: public LogType{
    LoggerPool* pool;
public:
    ErrorLog(LoggerPool* pool): pool(pool){};
    void fieldLog();
    void impassableLog();
    void endLog();
};