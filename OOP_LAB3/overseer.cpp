#include "overseer.hpp"
#include "field.hpp"
    void Overseer::eventProc(Field& field){
        field.getPlayer()->incHP(this->overseerLVL);
        field.getPlayer()->incAgility(this->overseerLVL);
        field.getPlayer()->incAttack(this->overseerLVL);
        field.getPlayer()->addScore(this->overseerLVL);
        field.getPlayer()->changeOverseer(true);
        std::cout << "You've found the mystic Overseer diadem! You've gained to stats and now you see everything on map!\n";
    }


    Overseer* Overseer::clone(){
        return new Overseer(*this);
    }