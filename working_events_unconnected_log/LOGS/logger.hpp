#pragma once

#include "logpool.hpp"
#include "gameloggen.hpp"
#include "infologgen.hpp"
#include "errorloggen.hpp"
#include "string"
#include "iostream"

class LogPool;
class GameLogGenerator;
class InfoLogGenerator;
class ErrorLogGenerator;

enum LogType{
    Game,
    Info,
    Error
};

class Logger{
    //LogPool pool;
    //LogGenerator gen;
    LogType type;
public:
    virtual void printLog() = 0;
    virtual LogType retType() = 0;
    virtual void newLog(std::string inpLog) = 0;
};

