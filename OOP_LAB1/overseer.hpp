#ifndef OVERSEER_HPP
#define OVERSEER_HPP

#include "map_events.hpp"

class Overseer: public Map_Events{
    int overseerLVL;
public:
    Overseer(int overseerLVL = 5):overseerLVL(overseerLVL){};
    void eventProc(Player& player);
    Overseer* clone() override;
};

#endif