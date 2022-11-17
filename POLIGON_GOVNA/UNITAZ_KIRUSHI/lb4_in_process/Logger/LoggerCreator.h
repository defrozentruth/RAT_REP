#include "ConsoleLogger.h"
#include "FileLogger.h"
#include <vector>
#include <iostream>
#pragma once

class LoggerCreator{
public:
    LoggerCreator() = default;
    std::vector<Logger*> create();
};