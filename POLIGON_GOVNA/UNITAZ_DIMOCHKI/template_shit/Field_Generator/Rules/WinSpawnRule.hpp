#pragma once

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"


template<int X, int Y>
class WinSpawnRule{
public:
    void update(FieldScheme& scheme){
        if( X >= 0 && Y >= 0 && X < scheme.getMask().size() && Y < scheme.getMask().size() && scheme.getMask()[Y][X] == Free)
            scheme.getMask()[Y][X] = WinM;
        else{
            LogPool::getInstance()->printLog(Error, "Wrong template data. Win set to last cell\n");
            scheme.getMask()[scheme.getMask().size()-1][scheme.getMask().size()-1] = WinM;
        }
    }
};
