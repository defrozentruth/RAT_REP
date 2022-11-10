#include "player.hpp"

Player& Player::operator=(const Player& obj){
        if(this != &obj){
            _hitPoints = obj._hitPoints;
            _points = obj._points;
            _power = obj._power;
        }
        return *this;
    }

int Player::getPower() const{
        return _power;
    }

void Player::setPower(int power){
    _power = power;
    //this->notify();
}

int Player::getHP() const{
    return _hitPoints;
}

void Player::setHP(int hp){
    _hitPoints = hp;
    //this->notify();
}

void Player::addPoints(int points){
    _points += points;
    //this->notify();
}

int Player::getPoints() const{
        return _points;
    }