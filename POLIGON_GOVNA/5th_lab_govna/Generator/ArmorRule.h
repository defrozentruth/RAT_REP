#pragma once
#include "../Field/Field.h"
#include "../Event/PlayerEvent/Breastplate.h"

template <int number>
class ArmorRule{
public:
    void place(Field* field);
};

template <int number>
void ArmorRule<number>::place(Field *field){
    int count = 0;
    while(count < number){
        int y = rand() % (field->getHeight() - 1);
        int x = rand() % (field->getWidth() - 1);
        if(field->getField()[y][x].getType() == Cell::cell_type::PASSABLE && (x != 0 && y != 0)){
            Breastplate armor = Breastplate();
            field->getField()[y][x].changeEvent(&armor);
            field->getField()[y][x].setType(Cell::cell_type::BREASTPLATE);
            count++;
        }
    }
}