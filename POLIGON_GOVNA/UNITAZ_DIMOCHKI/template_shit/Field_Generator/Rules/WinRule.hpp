#pragma once

#include <cstdlib>

#include "../FieldScheme.hpp"



template<int ... Args>
class WinRule{};

template<int Count>
class WinRule<Count>{
public:
    void update(FieldScheme& scheme){
        for(int i = 0; i < Count; i++){
                int x = rand() % scheme.getMask().size();
                int y = rand() % scheme.getMask().size();  
                scheme.getMask()[y][x] = WinM;
        }
    }
};

template<int X, int Y>
class WinRule<X, Y>{
public:
    void update(FieldScheme& scheme){
        scheme.getMask()[Y][X] = WinM;
        }
};

