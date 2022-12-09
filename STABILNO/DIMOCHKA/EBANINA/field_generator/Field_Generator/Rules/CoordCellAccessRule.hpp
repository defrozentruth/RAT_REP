#pragma once 

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"

#include <cstdlib>


template<int X, int Y>
class CoordCellAccessRule{
public:
    void update(FieldScheme& scheme){
        if(X >= 0 && Y>=0 && X < scheme.getMask().size() && Y < scheme.getMask().size() && scheme.getMask()[Y][X] == Free){
            scheme.getMask()[Y][X] = Block;
            for (int i = 0; i < scheme.getFreeCells().size(); i++){
                if(scheme.getFreeCells()[i].first == Y && scheme.getFreeCells()[i].second == X){
                    scheme.getFreeCells().erase(scheme.getFreeCells().begin()+i);
                    i--;
                }
            }
        }
        else
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
    }
};