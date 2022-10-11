#include "win.hpp"


    void Win::eventProc(Player& player){
        player.addScore(this->score);
        if (player.retScore() >= 100)
            player.changeWinState(WIN);
    }

    Win* Win::clone(){
        return new Win(*this);
    }