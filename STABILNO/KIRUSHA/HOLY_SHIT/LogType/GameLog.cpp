#include "GameLog.h"

void GameLog::moveLog(int x, int y){
    GameMessage msg("Player's position changed. New position: [" + std::to_string(x) + "," + std::to_string(y) + "]\n");
    pool->printLog(&msg);
}

void GameLog::enemyLog(char c){
    switch (c){
        case 'h': {
            GameMessage msg("You've stumbled upon an enemy!\nHeavy damage received!\n");
            pool->printLog(&msg);
            break;
        }
        case 'l':{
            GameMessage msg("You've stumbled upon an enemy!\nLight damage received!\n");
            pool->printLog(&msg);
            break;
        }
    }
}

void GameLog::healLog(){
    GameMessage msg("You used a healing potion! Health restored\n");
    pool->printLog(&msg);
}

void GameLog::plateLog(){
    GameMessage msg("You stepped on a strange slab! The sound of a door opening is heard from the corner\n");
    pool->printLog(&msg);
}

void GameLog::deathLog(){
    GameMessage msg("YOU DIED!\n");
    pool->printLog(&msg);
}

void GameLog::winLog(){
    GameMessage msg("You found a way out and got out of the dungeon!\n");
    pool->printLog(&msg);
}