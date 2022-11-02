#include <iostream>
#include "FieldView.h"
#include "../CellView/CellView.h"

void FieldView::printField(Field& field){
    Cell** temp = field.getField();
    CellView printer;
    for(int i = 0; i < field.getHeight(); i++) {
        for (int j = 0; j < field.getWidth(); j++) {
            printer.printCell(temp[i][j]);
        }
        std::cout << '\n';
    }
}