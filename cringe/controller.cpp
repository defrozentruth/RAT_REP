#include "controller.hpp"

void Controller::getCommand(char command){
    switch (command)
    {
    case 'w':
        this->command = UP; 
        break;
    case 'a':
        this->command = LEFT;
        break;
    case 's':
        this->command = DOWN;
        break;
    case 'd':
        this->command = RIGHT;
        break;
    case 'q':
        this->command = QUIT;
        break;
    default:
        break;
    }
}