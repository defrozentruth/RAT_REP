#pragma once

#include <cstdlib>

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"




template<int ... Args>
class TrapRule{};

template<int Count>
class TrapRule<Count>{
public:
    void update(FieldScheme& scheme){
        if(Count >= 0){
            for(int i = 0; i < Count; i++){
                int x = rand() % scheme.getMask().size();
                int y = rand() % scheme.getMask().size();
                scheme.getMask()[y][x] = TrapM;
            }
        }else
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
    }
};

template<int X, int Y>
class TrapRule<X, Y>{
public:
    void update(FieldScheme& scheme){
        if( X >= 0 && Y >= 0 && X < scheme.getMask().size() && Y < scheme.getMask().size())
            scheme.getMask()[Y][X] = TrapM;
        else
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
        }
};

