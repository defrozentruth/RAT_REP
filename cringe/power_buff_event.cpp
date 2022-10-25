#include "power_buff_event.hpp"

void PowerBuff::change_state(){
    player->setPower(player->getPower()+mult);
}

PowerBuff* PowerBuff::clone(){
    return new PowerBuff(*this);
}

PowerBuff::~PowerBuff(){
    mult = 0;
}