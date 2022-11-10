#include "ConsoleLog.hpp"
#include "FileLog.hpp"
#include "Message.hpp"
#include <vector>
#include <map>

#pragma once

class LogPool{
    std::vector<Logger*> pool;
    std::map <Level, bool> logLevels{
            {Level::Game, false},
            {Level::Info, false},
            {Level::Error, false}
    };
    static LogPool* instance;
public:
    static LogPool* getInstance();
    void addStream(std::string type);
    void addLevel(Level lvl);
    void printLog(Level lvl, std::string Message);
    bool logging(Level lvl);
    void clearLoggers();
};