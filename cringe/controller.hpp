#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "direction.hpp"

class Controller{
    
public:
    void getCommand(char command);
    direction command;
};

#endif