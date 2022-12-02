#pragma once
#include "../Field/Field.h"

template<int x, int y>
class PlayerRule{
public:
    void place(Field* field);
};

template<int x, int y>
void PlayerRule<x, y>::place(Field* field){
    field->setPlx(x);
    field->setPly(y);
    field->getField()[y][x].setType(Cell::ACTIVE);
}