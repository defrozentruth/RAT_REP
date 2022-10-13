#ifndef MAP_EVENTS_HPP
#define MAP_EVENTS_HPP

#include "event.hpp"


class Map_Events : public Event{
    virtual void eventProc(void* smth) = 0;
};

#endif