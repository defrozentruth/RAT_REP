#include "Enemy.h"
#include "../../Field/Field.h"
#include <iostream>
#include <windows.h>

void Enemy::processEvent(Field *field){
    Observer* obs = Observer::get();
    int res_hp = 0;
    if(field->getPlayer().getStrength() < 20){
        res_hp = field->getPlayer().getHp() - 50*(100 - field->getPlayer().getArmor())/100;
        field->getPlayer().setHp(res_hp);
        obs->notify(Message::Level::Game, "You've stumbled upon an enemy!\nHeavy damage received!\n");
    }
    else{
        res_hp = field->getPlayer().getHp() - 25*(1 - field->getPlayer().getArmor())/100;
        field->getPlayer().setHp(res_hp);
        obs->notify(Message::Level::Game, "You've stumbled upon an enemy!\nLight damage received!\n");
    }
    if(field->getPlayer().getHp() <= 0){
        system("cls");
        obs->notify(Message::Level::Game, "YOU DIED!\n");
        field->setFlag(-1);
    }
}

Enemy* Enemy::copy(){
    return new Enemy(*this);
}