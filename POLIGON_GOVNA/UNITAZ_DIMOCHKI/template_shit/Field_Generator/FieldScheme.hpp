#pragma once

#include <vector>


enum CellType{
    Free,
    PlayerPos, 
    Block,
    EventM,
    WinM
};

enum Events{
    EEnemy,
    EHeal,
    EOverseer,
    ETrap,
    EWin,
    ESledge
};

class FieldScheme{
    std::vector<std::vector <CellType>> mask;

public:
    FieldScheme() = default;
    std::vector<std::vector <CellType>>& getMask(){
        return mask;
    };
};