#include "player_event.hpp"

void Player_Event::procEvent(){
        int pos_x = field.getPlayerX();
        int pos_y = field.getPlayerY();
        if (field.getField()[pos_y][pos_x].haveEvent() == true){
                field.getField()[pos_y][pos_x].eventAccess()->changePlayer(player/*, field*/);
        }
    }