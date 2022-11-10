    #include "trap.hpp"
    #include "field.hpp"

    void Trap::eventProc(){
        if(this->player->retAgility() < this->lvl){
            //std::cout << "You fell into a pit and broke your leg!\n";
            this->player->decHP(this->lvl);
            if (this->player->retHP() <= 0)
                this->player->changeWinState(LOSE);
        }else{
            //std::cout << "You noticed a pit and jumped over it. You gain agility";
            this->player->incAgility(1);
        }
    }


    Trap* Trap::clone(){
        return new Trap(*this);
    }

    