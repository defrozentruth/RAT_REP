#include "Player.h"
#include <iostream>

Player::Player(int hp, int armor, int strength){
    this->hp = hp;
    this->armor = armor;
    this->strength = strength;
}
int Player::getHp(){
    return hp;
}
void Player::setHp(int hp){
    this->hp = hp;
}
void Player::setArmor(int armor){
    this->armor = armor;
}
int Player::getArmor(){
    return armor;
}
void Player::setStrength(int strength){
    this->strength = strength;
}
int Player::getStrength(){
    return strength;
}

void Player::seeParameters(){
    std::cout << "Player characteristics:\n" << "Hp: " << hp << "\nArmor: " << armor << "\nStrength: " << strength << '\n';
}