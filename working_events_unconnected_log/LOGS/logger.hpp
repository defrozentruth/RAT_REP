#pragma once

#include "logpool.hpp"
#include "gameloggen.hpp"
#include "infologgen.hpp"
#include "errorloggen.hpp"
#include "string"
#include "iostream"

enum LogType{
    Game,
    Info,
    Error
};

class Logger{
    LogPool pool;
    LogGenerator gen;
    LogType type;
public:
    virtual void printLog();
    virtual LogType retType();
    virtual void newLog(std::string inpLog);
};

