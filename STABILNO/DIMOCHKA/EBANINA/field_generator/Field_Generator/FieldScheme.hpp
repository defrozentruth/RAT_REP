#pragma once

#include <vector>
#include <utility>


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
    std::vector<std::pair<int, int>> freeCells;

public:
    FieldScheme() = default;
    std::vector<std::vector <CellType>>& getMask(){
        return mask;
    };
    std::vector<std::pair<int, int>>& getFreeCells(){
        return freeCells;
    }
};