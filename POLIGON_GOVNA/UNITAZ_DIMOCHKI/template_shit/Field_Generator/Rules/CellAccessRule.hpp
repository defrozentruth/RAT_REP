#pragma once 

#include "../FieldScheme.hpp"
#include <cstdlib>

template<int ... Args>
class CellAccessRule {};

template <int Count>
class CellAccessRule<Count>{
public:
    void update(FieldScheme& scheme){
        for(int i = 0; i < Count; i++){
            int x = rand() % scheme.getMask().size();
            int y = rand() % scheme.getMask().size();
            scheme.getMask()[y][x] = Block;
        }
    }
};

template<int X, int Y>
class CellAccessRule<X, Y>{
public:
    void update(FieldScheme& scheme){
        scheme.getMask()[Y][X] = Block;
    }
};