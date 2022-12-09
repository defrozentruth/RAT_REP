#pragma once 

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"

#include <cstdlib>


template<int X, int Start, int End>
class VertCellAccessLineRule{
public:
    void update(FieldScheme& scheme){
        if(X >= 0, X < scheme.getMask().size() && Start >= 0 && End > Start && Start < End && End < scheme.getMask().size())
            for (int i = Start; i <= End; i++){
                if(scheme.getMask()[i][X] == Free)
                    scheme.getMask()[i][X] = Block;
            }
        else
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
    }
};