#pragma once

#include "event.hpp"
//#include "field.hpp"
#include "player.hpp"
#include <iostream>

class Enemy:public Event{
    int lvl;
    int attack;
    int hp;
public:
    Enemy(int hp = 1, int attack = 1, int lvl = 1):hp(hp), attack(attack), lvl(lvl){};
    void changePlayer(Player& player/*, Field& field*/);
    Enemy* clone() override;
    void testEx();
    char retName();

};