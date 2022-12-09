#pragma once

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"

#include <cstdlib>

template<int X, int Y>
class CoordEventRule{
public:
    void update(FieldScheme& scheme){
        if(X >= 0 && Y>=0 && X < scheme.getMask().size() && Y < scheme.getMask().size() && scheme.getMask()[Y][X] == Free)
            scheme.getMask()[Y][X] = Block;
        else
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
    }
};