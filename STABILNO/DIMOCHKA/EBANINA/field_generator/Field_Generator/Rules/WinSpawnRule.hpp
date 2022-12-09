#pragma once

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"


template<int X, int Y>
class WinSpawnRule{
public:
    void update(FieldScheme& scheme){
        if( X >= 0 && Y >= 0 && X < scheme.getMask().size() && Y < scheme.getMask().size() && scheme.getMask()[Y][X] == Free){
            scheme.getMask()[Y][X] = WinM;
             for (int i = 0; i < scheme.getFreeCells().size(); i++){
                if(scheme.getFreeCells()[i].first == Y && scheme.getFreeCells()[i].second == X){
                    scheme.getFreeCells().erase(scheme.getFreeCells().begin()+i);
                    i--;
                }
            }
        }
        else{
            LogPool::getInstance()->printLog(Error, "Wrong template data. Win set to last cell\n");
            scheme.getMask()[scheme.getMask().size()-1][scheme.getMask().size()-1] = WinM;
             for (int i = 0; i < scheme.getFreeCells().size(); i++){
                if(scheme.getFreeCells()[i].first == scheme.getMask().size()-1 && scheme.getFreeCells()[i].second == scheme.getMask().size()-1){
                    scheme.getFreeCells().erase(scheme.getFreeCells().begin()+i);
                    i--;
                }
            }
        }
    }
};
