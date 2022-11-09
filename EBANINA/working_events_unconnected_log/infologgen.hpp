#pragma once

#include "loggen.hpp"

class InfoLogGenerator: public LogGenerator{
public:
    InfoLogGenerator() = default;
    //~InfoLogGenerator();
    Message* generateMessage(std::string inpLog);
};