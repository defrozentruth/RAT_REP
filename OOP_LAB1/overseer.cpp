#include "overseer.hpp"

    void Overseer::eventProc(Player& player){
        player.incHP(this->overseerLVL);
        player.incAgility(this->overseerLVL);
        player.incAttack(this->overseerLVL);
        player.addScore(this->overseerLVL);
        player.changeOverseer(true);
        std::cout << "You've found the mystic Overseer diadem! You've gained to stats and now you see everything on map!\n";
    }


    Overseer* Overseer::clone(){
        return new Overseer(*this);
    }