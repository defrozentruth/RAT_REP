#include "../Logger/LoggerPool.h"
#include <map>
#pragma once

class Observer{
    LoggerPool* pool;
    std::map <Message::Level, bool> logLevels{
            {Message::Level::Game, false},
            {Message::Level::Info, false},
            {Message::Level::Error, false}
    };
    Observer();
    static Observer* obs;
public:
    static Observer* get();
    void notify(Message::Level lvl, std::string msg);
    void setLoggers(LoggerPool* pool);
    void operator=(const Observer&) = delete;
    Observer(Observer& other) = delete;
};