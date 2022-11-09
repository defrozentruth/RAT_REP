#include "enemy.hpp"    
#include "field.hpp"

    void Enemy::eventProc(){
        LogPool* logger = LogPool::getInstance();
        if(logger->logging(Game) == true)
            logger->printLog(Game, "You're facing the enemy!\n");
        //std::cout << "You're facing enemy!\n";
        int playerHP = this->player->retHP();
        int enemyHP = this->hp;
        int round = 0;
        while(playerHP > 0 && enemyHP > 0){
            round++;
            enemyHP = enemyHP - this->player->retAttack();
            if (enemyHP <= 0)
                break;
            playerHP -= this->attack;
            //std::cout <<"Round: "<<round<<"     Player HP: "<<  playerHP << "   Enemy HP:" << enemyHP <<'\n';
        }
        if(enemyHP <= 0 && playerHP > 0){
            if(logger->logging(Game) == true)
            logger->printLog(Game, "You've won! You gain some points to your attack and hp!\n");
            //std::cout << "You've won! You gain some points to your attack and hp!\n";
            this->player->addScore(lvl);
            this->player->incAttack(lvl);
            this->player->incHP(lvl);
            if(this->player->retScore() >= 100){
                this->player->changeWinState(WIN);
            }
            
            this->player->setHP(playerHP);
        }else{
            if(logger->logging(Game) == true)
            logger->printLog(Game, "You have lost!\n");
            //std::cout << "You have lost!\n";
            this->player->changeWinState(LOSE);
        }
    }

    Enemy* Enemy::clone(){
        return new Enemy(*this);
    }

    