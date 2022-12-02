#include "Heal.h"
#include "../../Field/Field.h"
#include <iostream>

void Heal::processEvent(Field *field){
    Observer* obs = Observer::get();
    field->getPlayer().setHp(field->getPlayer().getHp() + 50);
    if(field->getPlayer().getHp() > 100){
        field->getPlayer().setHp(100);
    }
    obs->notify(Message::Level::Game, "You used a healing potion! Health restored\n");
//    std::cout << "You used a healing potion! Health restored\n";
}

Heal* Heal::copy(){
    return new Heal(*this);
}