#ifndef OVERSEER_HPP
#define OVERSEER_HPP

#include "../player_events.hpp"
#include "../../Logs/LogPool.hpp"

class Overseer: public Player_Events{
    int overseerLVL;
protected:
    Player* player;
public:
    Overseer(Player* player, int overseerLVL = 5): player(player), overseerLVL(overseerLVL){};
    void eventProc();
    Overseer* clone() override;
};

#endif