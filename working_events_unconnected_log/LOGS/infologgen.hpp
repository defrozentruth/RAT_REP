#pragma once

#include "loggen.hpp"

class InfoLogGenerator: public LogGenerator{
    InfoLogGenerator();
    ~InfoLogGenerator();
    Message* generateMessage(std::string inpLog);
};