#pragma once

#include <cstdlib>

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"




template<int ... Args>
class WinRule{};

template<int Count>
class WinRule<Count>{
public:
    void update(FieldScheme& scheme){
        if(Count >= 0){
            for(int i = 0; i < Count; i++){
                int x = rand() % scheme.getMask().size();
                int y = rand() % scheme.getMask().size();
                scheme.getMask()[y][x] = WinM;
            }
        }else
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
    }
};

template<int X, int Y>
class WinRule<X, Y>{
public:
    void update(FieldScheme& scheme){
        if( X >= 0 && Y >= 0 && X < scheme.getMask().size() && Y < scheme.getMask().size())
            scheme.getMask()[Y][X] = WinM;
        else
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
        }
};

