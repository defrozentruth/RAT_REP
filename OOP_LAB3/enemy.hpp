#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "player_events.hpp"
#include "LogPool.hpp"

class Enemy:public Player_Events{
    int lvl;
    int attack;
    int hp;
protected:
    Player* player;
public:
    Enemy(Player* player, int hp = 1, int attack = 1, int lvl = 1):player(player), hp(hp), attack(attack), lvl(lvl){};
    void eventProc();
    Enemy* clone() override;

};

#endif