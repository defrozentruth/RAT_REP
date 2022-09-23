
#include "fieldview.hpp"


    void FieldView::printField(Field& field){
        Cell** temp = field.getField();
        for(int i = 0; i < field.getHeight(); i++) {
            for (int j = 0; j < field.getWidth(); j++) {
                if(temp[i][j].isPassable()){
                    if(i == field.getPlayerY() && j == field.getPlayerX()){
                        std::cout << "[@]";
                    }
                    else{
                        std::cout << "[ ]";
                    }
                }
                else{
                    std::cout << "[#]";
                }
            }
            std::cout << '\n';
        }
    }
