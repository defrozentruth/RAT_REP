#include "player.hpp"

        Player::Player(int hp, int armor, int agility){
            this->hp = hp;
            this->armor = armor;
            this->agility = agility;
        }
        void Player::setHP(int hp){
            this->hp = hp;
        }
