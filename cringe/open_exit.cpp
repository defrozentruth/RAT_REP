#include "open_exit.hpp"

void Exit::change_state(){
    if(field->getPlayer()->getPoints() > 20){
        field->getField()[field->height()-1][field->width()-1].setEvent(new Win(field));
        //this->notify();
    }else{
        int old_x = field->player_x();
        int old_y = field->player_y();
        Exit* exit = new Exit(field);
        
        goToEmptyCell(old_x, old_y);
        
        field->getField()[old_y][old_x].setEvent(exit);
        //this->notify();
    }
}

Exit* Exit::clone(){
    return new Exit(*this);
}

void Exit::goToEmptyCell(int old_x, int old_y){
    if(field->getField()[old_y][old_x-1].getType() != Cell::IMPASSABLE){
            field->move(Player::LEFT);
        }else{
            if(field->getField()[old_y][old_x+1].getType() != Cell::IMPASSABLE){
                field->move(Player::RIGHT);
            }else{
                if(field->getField()[old_y-1][old_x].getType() != Cell::IMPASSABLE){
                    field->move(Player::DOWN);
                }else{
                    field->move(Player::UP);
                }
            }
        }
}