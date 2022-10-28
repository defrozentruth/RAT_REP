#pragma once

#include "message.hpp"
#include "string"

class LogGenerator{
public:
    virtual Message* generateMessage(std::string inpLog);
};