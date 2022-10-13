#include "win.hpp"
#include "player.hpp"


    void Win::eventProc(void* tmp_player){
        Player* player = (Player*)tmp_player;
        player->addScore(this->score);
        if (player->retScore() >= 100)
            player->changeWinState(WIN);
    }

    Win* Win::clone(){
        return new Win(*this);
    }