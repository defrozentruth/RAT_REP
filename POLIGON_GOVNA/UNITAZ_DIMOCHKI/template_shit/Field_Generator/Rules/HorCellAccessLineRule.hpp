#pragma once 

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"

#include <cstdlib>


template<int Y, int Start, int End>
class HorCellAccessLineRule{
public:
    void update(FieldScheme& scheme){
        if(Y >= 0, Y < scheme.getMask().size() && Start >= 0 && End > Start && Start < End && End < scheme.getMask().size())
            for (int i = Start; i <= End; i++){
                if (scheme.getMask()[Y][i] == Free)
                    scheme.getMask()[Y][i] = Block;
            }
        else
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
    }
};