#pragma once


#include "event.hpp"
#include "player.hpp"
//#include "field.hpp"
#include <iostream>

class Win: public Event{
    int a;
public:
    Win(int a):a(a){};
    void changePlayer(Player& player/*, Field& field*/);
    Win* clone() override;
    void testEx();
    char retName();
};