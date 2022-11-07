#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.hpp"
#include <map>

class Controller{
private:
    std::map<char, Player::command> control_scheme{
        {'w', Player::UP},
        {'a', Player::LEFT},
        {'s', Player::DOWN},
        {'d', Player::RIGHT},
        {'q', Player::QUIT},
        {'l', Player::LOGGER},
    };
public:
    void getCommand(char command);
    Player::command command;
};

#endif