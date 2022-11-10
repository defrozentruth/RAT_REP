#include "overseer.hpp"
#include "../../Map_Player/field.hpp"
    void Overseer::eventProc(){
        LogPool* logger = LogPool::getInstance();
        this->player->incHP(this->overseerLVL);
        this->player->incAgility(this->overseerLVL);
        this->player->incAttack(this->overseerLVL);
        this->player->addScore(this->overseerLVL);
        this->player->changeOverseer(true);
        if(logger->logging(Game) == true)
            logger->printLog(Game, "You've found the mystic Overseer diadem! You've gained to stats and now you see everything on map!\n");
        //std::cout << "You've found the mystic Overseer diadem! You've gained to stats and now you see everything on map!\n";
    }


    Overseer* Overseer::clone(){
        return new Overseer(*this);
    }

    