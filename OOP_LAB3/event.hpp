#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>

class Field;
class Player;

class Event{
public:
    virtual Event* clone() = 0;
    virtual void eventProc() = 0;
};

#endif