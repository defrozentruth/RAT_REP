#include "player.hpp"

        Player::Player(int hp, int agility, int attack){
            this->hp = hp;
            this->agility = agility;
            this->attack = attack;
            this->winState = 0;
            this->score = 0;
            this->overseer = true;
        }
        void Player::decHP(int hp){
            this->hp = this->hp - hp;
        }

        void Player::setHP(int hp){
            this->hp = hp;
        }

        int Player::retHP(){
            return this->hp;
        }

        int Player::retAgility(){
            return this->agility;
        }

        int Player::retAttack(){
            return this->attack;
        }

        void Player::incHP(int hp){
            this->hp = this->hp + hp;
        }

        void Player::incAgility(int ag){
            this->agility = this->agility + ag;
        }

        void Player::incAttack(int atk){
            this->attack = this->attack + atk;
        }

        void Player::changeWinState(int state){
            this->winState = state;
        }

        int Player::retWinState(){
            return this->winState;
        }

        void Player::changeOverseer(bool state){
            this->overseer = state;
        }

        bool Player::retOverseer(){
            return this->overseer;
        }

        int Player::retScore(){
            return this->score;
        }

        void Player::addScore(int score){
            this->score += score;
        }