#pragma once

#include <cstdlib>

#include "../FieldScheme.hpp"



template<int ... Args>
class OverseerRule{};

template<int Count>
class OverseerRule<Count>{
public:
    void update(FieldScheme& scheme){
        for(int i = 0; i < Count; i++){
            int x = rand() % scheme.getMask().size();
            int y = rand() % scheme.getMask().size();
            scheme.getMask()[y][x] = OverseerM;
        }
    }
};

template<int X, int Y>
class OverseerRule<X, Y>{
public:
    void update(FieldScheme& scheme){
        scheme.getMask()[Y][X] = OverseerM;
        }
};

