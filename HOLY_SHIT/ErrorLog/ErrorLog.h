#include "../ErrorMessage/ErrorMessage.h"
#include "../LoggerPool/LoggerPool.h"
#include "../LogType/LogType.h"
#pragma once

class ErrorLog: public LogType{
    LoggerPool* pool;
public:
    ErrorLog(LoggerPool* pool): pool(pool){};
    void fieldLog();
    void impassableLog();
    void endLog();
};