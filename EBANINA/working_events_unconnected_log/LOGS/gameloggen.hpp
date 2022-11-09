#pragma once

#include "loggen.hpp"

class GameLogGenerator: public LogGenerator{
    GameLogGenerator();
    ~GameLogGenerator();
    Message* generateMessage(std::string inpLog);
};