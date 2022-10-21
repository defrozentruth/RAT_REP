#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "player_events.hpp"

class Enemy:public Player_Events{
    int lvl;
    int attack;
    int hp;
public:
    Enemy(int hp = 1, int attack = 1, int lvl = 1):hp(hp), attack(attack), lvl(lvl){};
    void eventProc(Field& field);
    Enemy* clone() override;

};

#endif