    #include "trap.hpp"
    #include "field.hpp"

    void Trap::eventProc(Field& field){
        if(field.getPlayer()->retAgility() < this->lvl){
            std::cout << "You fell into a pit and broke your leg!\n";
            field.getPlayer()->decHP(this->lvl);
            if (field.getPlayer()->retHP() <= 0)
                field.getPlayer()->changeWinState(LOSE);
        }else{
            std::cout << "You noticed a pit and jumped over it. You gain agility";
            field.getPlayer()->incAgility(1);
        }
    }


    Trap* Trap::clone(){
        return new Trap(*this);
    }