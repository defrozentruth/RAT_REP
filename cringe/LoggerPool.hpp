#ifndef LOGGER_POOL_HPP
#define LOGGER_POOL_HPP

#include "ConsoleLogger.hpp"
#include "FileLogger.hpp"
#include "message.hpp"
#include <map>
#include <vector>

class LoggerPool{
public:    
    LoggerPool() = default;
    void addLog(Message* msg);
    void addLogger(Logger* logger);
    void deleteLoggers();
    bool isLogging(LogType type);
    void setLogTypes(std::vector<LogType> types);
    void printLogs();
private:
    std::vector<Message*> logs;
    std::vector<Logger*> Loggers;
    std::map<LogType, bool> logTypes{
        {LogType::GAME, false},
        {LogType::ERROR, false}, 
        {LogType::INFO, false}
    };
};

#endif