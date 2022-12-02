#pragma once

#include <cstdlib>

#include "../FieldScheme.hpp"



template<int ... Args>
class SledgeRule{};

template<int Count>
class SledgeRule<Count>{
public:
    void update(FieldScheme& scheme){
        for(int i = 0; i < Count; i++){
            int x = rand() % scheme.getMask().size();
            int y = rand() % scheme.getMask().size();
            scheme.getMask()[y][x] = SledgeM;
        }
    }
};

template<int X, int Y>
class SledgeRule<X, Y>{
public:
    void update(FieldScheme& scheme){
        scheme.getMask()[Y][X] = SledgeM;
        }
};

