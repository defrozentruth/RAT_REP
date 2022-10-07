#pragma once

#include "player.hpp"
//#include "field.hpp"

class Event{
public:
    Event() = default;
    virtual Event* clone() = 0;
    virtual void changePlayer(Player& player/*, Field& field*/) = 0;
    virtual void testEx() = 0;
    virtual char retName() = 0;
};