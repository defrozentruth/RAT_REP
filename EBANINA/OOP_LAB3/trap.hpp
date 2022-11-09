#ifndef TRAP_HPP
#define TRAP_HPP

#include "player_events.hpp"
#include "LogPool.hpp"

class Trap:public Player_Events{
    int lvl;
protected:
    Player* player;
public:
    Trap(Player* player, int lvl = 1):player(player), lvl(lvl){};
    void eventProc();
    Trap* clone() override;
};

#endif