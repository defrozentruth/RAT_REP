#include "controller.hpp"

void Controller::getCommand(char command){
    switch (command)
    {
    case 'w':
        this->command = Player::UP; 
        break;
    case 'a':
        this->command = Player::LEFT;
        break;
    case 's':
        this->command = Player::DOWN;
        break;
    case 'd':
        this->command = Player::RIGHT;
        break;
    case 'q':
        this->command = Player::QUIT;
        break;
    default:
        break;
    }
}