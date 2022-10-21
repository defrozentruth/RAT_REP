#ifndef MAP_EVENTS_HPP
#define MAP_EVENTS_HPP

#include "event.hpp"


class Map_Events : public Event{
    virtual void eventProc(Field& field) = 0;
};

#endif