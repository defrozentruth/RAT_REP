#ifndef EVENT_HPP
#define EVENT_HPP

#include "player.hpp"
#include <iostream>


class Event{
public:
    Event() = default;
    virtual Event* clone() = 0;
    virtual void eventProc(Player& player) = 0;
};

#endif