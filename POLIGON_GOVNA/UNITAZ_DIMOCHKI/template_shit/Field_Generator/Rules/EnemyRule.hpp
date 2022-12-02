#pragma once

#include <cstdlib>

#include "../FieldScheme.hpp"



template<int ... Args>
class EnemyRule{};

template<int Count>
class EnemyRule<Count>{
public:
    void update(FieldScheme& scheme){
        for(int i = 0; i < Count; i++){
            int x = rand() % scheme.getMask().size();
            int y = rand() % scheme.getMask().size();
            scheme.getMask()[y][x] = EnemyM;
        }
    }
};

template<int X, int Y>
class EnemyRule<X, Y>{
public:
    void update(FieldScheme& scheme){
        scheme.getMask()[Y][X] = EnemyM;
        }
};

