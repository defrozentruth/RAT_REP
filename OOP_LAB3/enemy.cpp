#include "enemy.hpp"    
#include "field.hpp"

    void Enemy::eventProc(Field& field){
        std::cout << "You're facing enemy!\n";
        int playerHP = field.getPlayer()->retHP();
        int enemyHP = this->hp;
        int round = 0;
        while(playerHP > 0 && enemyHP > 0){
            round++;
            enemyHP = enemyHP - field.getPlayer()->retAttack();
            if (enemyHP <= 0)
                break;
            playerHP -= this->attack;
            std::cout <<"Round: "<<round<<"     Player HP: "<<  playerHP << "   Enemy HP:" << enemyHP <<'\n';
        }
        if(enemyHP <= 0 && playerHP > 0){
            std::cout << "You've won! You gain some points to your attack and hp!\n";
            field.getPlayer()->addScore(lvl);
            field.getPlayer()->incAttack(lvl);
            field.getPlayer()->incHP(lvl);
            if(field.getPlayer()->retScore() >= 100){
                field.getPlayer()->changeWinState(WIN);
            }
            
            field.getPlayer()->setHP(playerHP);
        }else{
            std::cout << "You have lost!\n";
            field.getPlayer()->changeWinState(LOSE);
        }
    }

    Enemy* Enemy::clone(){
        return new Enemy(*this);
    }

