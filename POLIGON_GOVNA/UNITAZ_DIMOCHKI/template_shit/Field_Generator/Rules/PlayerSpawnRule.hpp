#pragma once

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"


template<int X, int Y>
class PlayerSpawnRule{
public:
    void update(FieldScheme& scheme){
        if( X >= 0 && Y >= 0 && X < scheme.getMask().size() && Y < scheme.getMask().size() && scheme.getMask()[Y][X] == Free)
            scheme.getMask()[Y][X] = PlayerPos;
        else
            LogPool::getInstance()->printLog(Error, "Wrong template data. Player set to [0][0]\n");
            scheme.getMask()[0][0] = PlayerPos;
    }
};
