#include "Heal.h"
#include "../Field/Field.h"
#include <iostream>

void Heal::processEvent(Field *field, GameLog* GL){
    field->getPlayer().setHp(field->getPlayer().getHp() + 50);
    if(field->getPlayer().getHp() > 100){
        field->getPlayer().setHp(100);
    }
    GL->healLog();
//    std::cout << "You used a healing potion! Health restored\n";
}

Heal* Heal::copy(){
    return new Heal(*this);
}