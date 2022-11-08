#include "win.hpp"
#include "field.hpp"

    void Win::eventProc(){
        LogPool* logger = LogPool::getInstance();
        if(logger->logging(Game) == true)
            logger->printLog(Game, "You've found the treasures!\n");
        player->addScore(this->score);
        if (this->player->retScore() >= 100)
            this->player->changeWinState(WIN);
    }

    Win* Win::clone(){
        return new Win(*this);
    }
