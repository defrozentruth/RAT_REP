#include "earthquake.hpp"

Earthquake* Earthquake::clone(){
        return new Earthquake(*this);
    }

void Earthquake::eventProc(void* tmp_field){
    Field* field = (Field*)tmp_field;
    std::cout << "You've stepped on some plate and ground started shaking!";
        int player_x = field->getPlayerX();
        int player_y = field->getPlayerY();
        int size_x = field->getWidth();
        int size_y = field->getHeight();
        if(player_x+1 >= size_x){
            if(field->getField()[player_y][0].haveEvent() != true){
                field->getField()[player_y][0].changeAccess(false);
            }
        }else{
            if(field->getField()[player_y][player_x+1].haveEvent() != true){
                field->getField()[player_y][player_x+1].changeAccess(false);
            }
        }

        if(player_x-1 <= 0){
            if(field->getField()[player_y][size_x-1].haveEvent() != true){
                field->getField()[player_y][size_x-1].changeAccess(false);
            }
        }else{
            if(field->getField()[player_y][player_x-1].haveEvent() != true){
                field->getField()[player_y][player_x-1].changeAccess(false);
            }
        }

        if(player_y+1 == size_y){
            if(field->getField()[0][player_x].haveEvent() != true){
                field->getField()[0][player_x].changeAccess(false);
            }
        }else{
            if(field->getField()[player_y+1][player_x].haveEvent() != true){
                field->getField()[player_y+1][player_x].changeAccess(false);
            }
        }
        
    }