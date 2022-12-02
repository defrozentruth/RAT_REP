#pragma once
#include "../Field/Field.h"
#include "../Event/MapEvent/PressurePlate.h"

template <int number>
class PlateRule{
public:
    void place(Field* field);
};

template <int number>
void PlateRule<number>::place(Field *field){
    int count = 0;
    while(count < number){
        int y = rand() % (field->getHeight() - 1);
        int x = rand() % (field->getWidth() - 1);
        if(field->getField()[y][x].getType() == Cell::cell_type::PASSABLE && (x != 0 && y != 0)){
            PressurePlate plate = PressurePlate();
            field->getField()[y][x].changeEvent(&plate);
            field->getField()[y][x].setType(Cell::cell_type::PLATE);
            count++;
        }
    }
}