#pragma once

#include <cstdlib>

#include "../FieldScheme.hpp"



template<int ... Args>
class TrapRule{};

template<int Count>
class TrapRule<Count>{
public:
    void update(FieldScheme& scheme){
        for(int i = 0; i < Count; i++){
            int x = rand() % scheme.getMask().size();
            int y = rand() % scheme.getMask().size();
            scheme.getMask()[y][x] = TrapM;
        }
    }
};

template<int X, int Y>
class TrapRule<X, Y>{
public:
    void update(FieldScheme& scheme){
        scheme.getMask()[Y][X] = TrapM;
        }
};

