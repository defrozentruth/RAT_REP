#include "win.hpp"

    void Win::changePlayer(Player& player/*, Field& field*/){
        player.changeWinState(WIN);
    }

    void Win::testEx(){
        std::cout << "trap exists\n";
    }

    char Win::retName(){
        return 'W';
    }

    Win* Win::clone(){
        return new Win(*this);
    }