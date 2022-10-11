#include "enemy.hpp"    

    void Enemy::eventProc(Player& player){
        std::cout << "You're facing enemy!\n";
        int playerHP = player.retHP();
        int enemyHP = this->hp;
        int round = 0;
        while(playerHP > 0 && enemyHP > 0){
            round++;
            playerHP -= this->attack;
            enemyHP = enemyHP - player.retAttack();
            std::cout <<"Round: "<<round<<"     Player HP: "<<  playerHP << "   Enemy HP:" << enemyHP <<'\n';
        }
        if(enemyHP <= 0 && playerHP > 0){
            std::cout << "You've won! You gain some points to your attack and hp!\n";
            player.addScore(lvl);
            player.incAttack(lvl);
            player.incHP(lvl);
            if(player.retScore() >= 100){
                player.changeWinState(WIN);
            }
            
            player.setHP(playerHP);
        }else{
            std::cout << "You have lost!\n";
            player.changeWinState(LOSE);
        }
    }

    Enemy* Enemy::clone(){
        return new Enemy(*this);
    }

