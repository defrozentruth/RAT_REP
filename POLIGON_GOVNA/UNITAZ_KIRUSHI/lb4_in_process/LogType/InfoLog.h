#include "../Message/InfoMessage.h"
#include "../Logger/LoggerPool.h"
#include "LogType.h"
#pragma once

class InfoLog: public LogType{
    LoggerPool* pool;
public:
    InfoLog(LoggerPool* pool): pool(pool){};
    void endLog();
};