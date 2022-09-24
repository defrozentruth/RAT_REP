#include "cell_view.hpp"

void CellView::printCell(Cell& cell){
        if(cell.getIsPassable()){
            if(cell.getIsPushed()){
                std::cout<<"[*]";
            }else{
                std::cout<<"[ ]";
            }
        }else{
            std::cout<<"[#]";
        }
    }