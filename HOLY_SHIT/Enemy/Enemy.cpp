#include "Enemy.h"
#include "../Field/Field.h"
#include <iostream>
#include <windows.h>

void Enemy::processEvent(Field *field, GameLog* GL){
    int res_hp = 0;
    if(field->getPlayer().getStrength() < 20){
        res_hp = field->getPlayer().getHp() - 50*(100 - field->getPlayer().getArmor())/100;
        field->getPlayer().setHp(res_hp);
        GL->enemyLog('h');
    }
    else{
        res_hp = field->getPlayer().getHp() - 25*(1 - field->getPlayer().getArmor())/100;
        field->getPlayer().setHp(res_hp);
        GL->enemyLog('l');
    }
    if(field->getPlayer().getHp() <= 0){
        system("cls");
        GL->deathLog();
        field->setFlag(-1);
    }
}

Enemy* Enemy::copy(){
    return new Enemy(*this);
}