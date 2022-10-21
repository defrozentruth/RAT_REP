#ifndef TRAP_HPP
#define TRAP_HPP

#include "player_events.hpp"

class Trap:public Player_Events{
    int lvl;
public:
    Trap(int lvl = 1):lvl(lvl){};
    void eventProc(Field& field) final;
    Trap* clone() override;
    char retName();
};

#endif