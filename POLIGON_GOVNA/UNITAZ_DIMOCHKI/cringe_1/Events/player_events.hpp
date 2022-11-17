#ifndef PLAYER_EVENTS_HPP
#define PLAYER_EVENTS_HPP

#include "event.hpp"

class Player_Events : public Event {
public:
    virtual void eventProc() = 0;

protected:
    Player* player;
};
#endif
