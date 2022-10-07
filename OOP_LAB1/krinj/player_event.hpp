#pragma once

#include <iostream>
// #include "cell.hpp"
#include "field.hpp"
//#include "event.hpp"
#include "player.hpp"
// #include "trap.hpp"
// #include "enemy.hpp"
// #include "win.hpp"
// #include "earthquake.hpp"

class Player_Event{
    Field field;
    Player player;
public:
    Player_Event(Player& player, Field& field):player(player), field(field){};
    void procEvent();
};