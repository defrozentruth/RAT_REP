#pragma once

#include <iostream>
#include "event.hpp"
#include "player.hpp"
//#include "field.hpp"

class Earthquake:public Event{
    int agilityCheck;
    int lvl;
public:
    Earthquake(int agilityCheck = 1, int lvl = 1):agilityCheck(agilityCheck), lvl(lvl){};
    void changePlayer(Player& player/*, Field& field*/);
    Earthquake* clone() override;
    void testEx();
    char retName();
};