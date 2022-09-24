#ifndef EVENT_HPP
#define EVENT_HPP

#include "cell.hpp"

class Event{

public:
    virtual ~Event() = 0;
    virtual void change_statement() = 0;
};

#endif