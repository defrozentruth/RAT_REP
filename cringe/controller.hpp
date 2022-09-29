#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.hpp"

class Controller{
    
public:
    void getCommand(char command);
    Player::direction command;
};

#endif