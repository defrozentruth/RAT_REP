#include <iostream>
#include "CellView.h"

void CellView::printCell(Cell& cell){
    switch(cell.getType()){
        case Cell::PASSABLE:
            std::cout << "[ ]";
            break;
        case Cell::IMPASSABLE:
            std::cout << "[#]";
            break;
        case Cell::ACTIVE:
            std::cout << "[@]";
            break;
        case Cell::HEAL:
            std::cout << "[+]";
            break;
        case Cell::ENEMY:
            std::cout << "[*]";
            break;
        case Cell::PLATE:
            std::cout << "[_]";
            break;
        case Cell::VICTORY:
            std::cout << "[W]";
            break;
    }
}