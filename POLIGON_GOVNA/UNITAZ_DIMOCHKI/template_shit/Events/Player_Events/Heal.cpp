#include "Heal.hpp"
#include "../../Map_Player/field.hpp"
    void Heal::eventProc(){
        LogPool* logger = LogPool::getInstance();
        this->player->incHP(this->lvl);
        if(logger->logging(Game) == true){
            logger->printLog(Game, "You've found a healing flask!\n");
        }
    }


    Heal* Heal::clone(){
        return new Heal(*this);
    }

    