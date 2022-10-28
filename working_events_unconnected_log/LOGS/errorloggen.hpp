#pragma once

#include "loggen.hpp"

class ErrorLogGenerator: public LogGenerator{
public:
    ErrorLogGenerator();
    ~ErrorLogGenerator();
    Message* generateMessage(std::string inpLog);
};