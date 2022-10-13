#ifndef PLAYER_EVENTS_HPP
#define PLAYER_EVENTS_HPP

#include "event.hpp"

class Player_Events:public Event{
    virtual void eventProc(void* smth) = 0;
};
#endif