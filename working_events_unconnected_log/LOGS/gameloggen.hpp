#pragma once

#include "loggen.hpp"

class GameLogGenerator: public LogGenerator{
public:
    GameLogGenerator();
    ~GameLogGenerator();
    Message* generateMessage(std::string inpLog);
};