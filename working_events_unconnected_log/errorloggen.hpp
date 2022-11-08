#pragma once

#include "loggen.hpp"

class ErrorLogGenerator: public LogGenerator{
public:
    ErrorLogGenerator() = default;
    //~ErrorLogGenerator();
    Message* generateMessage(std::string inpLog);
};