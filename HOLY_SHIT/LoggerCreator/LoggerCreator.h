#include "../ConsoleLogger/ConsoleLogger.h"
#include "../FileLogger/FileLogger.h"
#include <iostream>
#pragma once

class LoggerCreator{
public:
    LoggerCreator() = default;
    Logger** create();
};