#include "../Logger.h"
#pragma once

class ConsoleLogger: public Logger{
public:
    ConsoleLogger() = default;
    void print(Message* msg) override;
    ~ConsoleLogger() = default;
};