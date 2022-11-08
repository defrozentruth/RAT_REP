#ifndef EVENT_HPP
#define EVENT_HPP

#include "player.hpp"
#include "observable.hpp"

class Event{//сделать на смартуказателях

public:
    virtual void change_state() = 0;
    virtual Event* clone() = 0;
};

#endif