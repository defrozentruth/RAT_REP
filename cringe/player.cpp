#include "player.hpp"

Player& Player::operator=(const Player& obj){
        if(this != &obj){
            _hitPoints = obj._hitPoints;
            _mana = obj._mana;
            _power = obj._power;
        }
        return *this;
    }