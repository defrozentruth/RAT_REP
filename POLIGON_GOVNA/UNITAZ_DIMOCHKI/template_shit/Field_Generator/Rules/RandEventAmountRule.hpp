#pragma once

#include <cstdlib>

#include "../FieldScheme.hpp"
#include "../../Logs/LogPool.hpp"

template<int Count>

class RandEventAmountRule{
public:
    void update(FieldScheme& scheme){
        if (Count >= 0){
            for(int i = 0; i < Count; i++){
                std::random_device rd; // obtain a random number from hardware
                std::mt19937 gen(rd()); // seed the generator
                std::uniform_int_distribution<> distr(0, scheme.getMask().size()-1); // define the range
                int x = distr(gen);
                int y = distr(gen);
                if (scheme.getMask()[y][x] == Free)
                    scheme.getMask()[y][x] = EventM;
                else
                    i--;
            }
        }else{
            LogPool::getInstance()->printLog(Error, "Wrong template data\n");
        }
    }
};