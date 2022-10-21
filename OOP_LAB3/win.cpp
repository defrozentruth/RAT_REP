#include "win.hpp"
#include "field.hpp"

    void Win::eventProc(Field& field){
        field.getPlayer()->addScore(this->score);
        if (field.getPlayer()->retScore() >= 100)
            field.getPlayer()->changeWinState(WIN);
    }

    Win* Win::clone(){
        return new Win(*this);
    }