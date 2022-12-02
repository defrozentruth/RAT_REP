#pragma once

#include "../FieldScheme.hpp"

template<int X, int Y>
class PlayerSpawnRule{
public:
    void update(FieldScheme& scheme){
        scheme.getMask()[Y][X] = PlayerPos;
    }
};
