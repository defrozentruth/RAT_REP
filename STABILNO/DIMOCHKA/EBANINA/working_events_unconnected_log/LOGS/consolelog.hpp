#pragma once

#include "logger.hpp"

class ConsoleLogger: public Logger{
    LogPool pool;
    LogType type;
    LogGenerator gen;
public:
    ConsoleLogger(LogType type): type(type){};
    ~ConsoleLogger();
    void printLog();
    LogType retType();
    void newLog(std::string inpLog);
};