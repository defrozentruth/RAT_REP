#ifndef POWER_BUFF_HPP
#define POWER_BUFF_HPP

#include "event.hpp"
#include "player.hpp"
#include <iostream>

class PowerBuff:public Event{
    int mult;
public:
    ~PowerBuff();
    PowerBuff(int mult = 10000):mult(mult){};
    void change_state(Player& player);
    Event* clone();
};

#endif