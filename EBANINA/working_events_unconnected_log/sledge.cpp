#include "sledge.hpp"
#include "field.hpp"

Sledge* Sledge::clone(){
    return new Sledge(*this);
}

void Sledge::eventProc(){
    int size_x = field->getWidth();
    int size_y = field->getHeight();
    for (int i = 0; i < size_y; i++){
        for (int j = 0; j < size_x; j++){
            field->getField()[i][j].changeAccess(true);
        }
    }
}