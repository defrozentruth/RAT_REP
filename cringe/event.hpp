#ifndef EVENT_HPP
#define EVENT_HPP

#include "player.hpp"

class Event{

public:
    virtual void change_state(Player& player) = 0;
    virtual Event* clone() = 0;
    // virtual ~Event() = 0;
};

#endif