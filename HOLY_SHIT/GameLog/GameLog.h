#include "../GameMessage/GameMessage.h"
#include "../LoggerPool/LoggerPool.h"
#include "../LogType/LogType.h"
#pragma once

class GameLog: public LogType{
    LoggerPool* pool;
public:
    GameLog(LoggerPool* pool): pool(pool){};
    void moveLog(int x, int y);
    void enemyLog(char c);
    void healLog();
    void plateLog();
    void deathLog();
    void winLog();
};