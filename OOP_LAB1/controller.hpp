#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "field.hpp"
#include "player.hpp"
#include <iostream>


class Controller{
    public:
        void mover(char movement, Field& field, Player& player);
};

#endif