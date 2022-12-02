#include "Breastplate.h"
#include "../../Field/Field.h"
#include <iostream>

void Breastplate::processEvent(Field *field){
    Observer* obs = Observer::get();
    field->getPlayer().setHp(field->getPlayer().getArmor() + 10);
    if(field->getPlayer().getArmor() > 100){
        field->getPlayer().setArmor(100);
    }
    obs->notify(Message::Level::Game, "You found the steel breastplate! Armor increased\n");
//    std::cout << "You used a healing potion! Health restored\n";
}

Breastplate* Breastplate::copy(){
    return new Breastplate(*this);
}