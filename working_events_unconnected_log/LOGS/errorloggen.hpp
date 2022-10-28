#pragma once

#include "loggen.hpp"

class ErrorLogGenerator: public LogGenerator{
    ErrorLogGenerator();
    ~ErrorLogGenerator();
    Message* generateMessage(std::string inpLog);
};