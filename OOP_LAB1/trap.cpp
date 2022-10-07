    #include "trap.hpp"
    
    void Trap::changePlayer(Player& player/*, Field& field*/){
        std::cout << "You fell into a pit and broke your leg!\n";
        player.decHP(decrement);
    }

    void Trap::testEx(){
        std::cout << "trap exists\n";
    }

    char Trap::retName(){
        return 'T';
    }

    Trap* Trap::clone(){
        return new Trap(*this);
    }