#include "ConsoleLog.hpp"
#include "FileLog.hpp"
#include "Message.hpp"
#include <vector>
#include <map>

#pragma once

class LogPool{
    std::vector<Logger*> pool;
    std::map <LogLevel, bool> logLevels{
            {LogLevel::Game, false},
            {LogLevel::Info, false},
            {LogLevel::Error, false}
    };
    LogPool() = default;
    static LogPool* instance;
public:
    static LogPool* getInstance();
    void addStream(std::string type);
    void addLevel(LogLevel lvl);
    void printLog(LogLevel lvl, std::string Message);
    bool logging(LogLevel lvl);
    void clearLoggers();
    void operator=(const LogPool&) = delete;
    LogPool(LogPool& other) = delete;
};