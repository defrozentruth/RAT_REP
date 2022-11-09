#include "Logger.hpp"
#pragma once

class ConsoleLog: public Logger{
public:
    ConsoleLog() = default;
    ~ConsoleLog() = default;
    void output(Message* msg) override;
};