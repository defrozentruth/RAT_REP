#pragma once

#include "loggen.hpp"

class GameLogGenerator: public LogGenerator{
public:
    GameLogGenerator() = default;
    //~GameLogGenerator();
    Message* generateMessage(std::string inpLog);
};