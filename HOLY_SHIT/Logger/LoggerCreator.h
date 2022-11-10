#include "../Logger/ConsoleLogger/ConsoleLogger.h"
#include "../Logger/FileLogger/FileLogger.h"
#include <iostream>
#pragma once

class LoggerCreator{
public:
    LoggerCreator() = default;
    Logger** create();
};