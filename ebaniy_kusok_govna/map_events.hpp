#ifndef MAP_EVENTS_HPP
#define MAP_EVENTS_HPP

#include "event.hpp"


class Map_Events : public Event{
public:
    virtual void eventProc() = 0;
protected:
    Field* field;
};

#endif