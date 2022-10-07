#pragma once
#include "event.hpp"
#include "player.hpp"
//#include "field.hpp"
#include <iostream>

class Trap:public Event{
    int decrement;
public:
    Trap(int decrement = 1):decrement(decrement){};
    void changePlayer(Player& player/*, Field& field*/);
    Trap* clone() override;
    void testEx();
    char retName();
};