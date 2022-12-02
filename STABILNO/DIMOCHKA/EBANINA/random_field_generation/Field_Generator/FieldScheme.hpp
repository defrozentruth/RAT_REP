#pragma once

#include <vector>


enum CellType{
    Free,
    PlayerPos, 
    Block,
    SledgeM,
    EnemyM,
    OverseerM,
    TrapM,
    WinM
};



class FieldScheme{
    std::vector<std::vector <CellType>> mask;

public:
    FieldScheme() = default;
    std::vector<std::vector <CellType>>& getMask(){
        return mask;
    };
};