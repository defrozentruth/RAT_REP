#include "power_buff_event.hpp"


void PowerBuff::change_state(Player& player){
    player.setPower(player.getPower()*mult);
}

Event* PowerBuff::clone(){
    return new PowerBuff(mult);
}

PowerBuff::~PowerBuff(){
    mult = 1;
}