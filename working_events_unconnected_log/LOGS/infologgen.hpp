#pragma once

#include "loggen.hpp"

class InfoLogGenerator: public LogGenerator{
public:
    InfoLogGenerator();
    ~InfoLogGenerator();
    Message* generateMessage(std::string inpLog);
};