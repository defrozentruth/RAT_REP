#ifndef EVENT_HPP
#define EVENT_HPP

// #include "player.hpp"
#include <iostream>

class Field;

class Event{
public:
    virtual Event* clone() = 0;
    virtual void eventProc(Field& field) = 0;
};

#endif