#include "win.hpp"
#include "field.hpp"

    void Win::eventProc(){
        player->addScore(this->score);
        if (this->player->retScore() >= 100)
            this->player->changeWinState(WIN);
    }

    Win* Win::clone(){
        return new Win(*this);
    }