#ifndef HEAL_HPP
#define HEAL_HPP

#include "../player_events.hpp"
#include "../../Logs/LogPool.hpp"

class Heal: public Player_Events{
    int lvl;
protected:
    Player* player;
public:
    Heal(Player* player, int lvl = 5): player(player), lvl(lvl){};
    void eventProc();
    Heal* clone() override;
};

#endif