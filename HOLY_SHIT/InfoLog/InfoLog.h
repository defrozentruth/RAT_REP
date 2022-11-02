#include "../InfoMessage/InfoMessage.h"
#include "../LoggerPool/LoggerPool.h"
#include "../LogType/LogType.h"
#pragma once

class InfoLog: public LogType{
    LoggerPool* pool;
public:
    InfoLog(LoggerPool* pool): pool(pool){};
    void endLog();
};