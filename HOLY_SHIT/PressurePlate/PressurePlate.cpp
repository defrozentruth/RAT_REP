#include "PressurePlate.h"
#include "../Field/Field.h"
#include "../Victory/Victory.h"
#include <iostream>

void PressurePlate::processEvent(Field *field, GameLog* GL){
    Victory win = Victory();
    int x = field->getWidth()-1;
    int y = field->getHeight()-1;
    field->getField()[y][x].changeEvent(&win);
    field->getField()[y][x].setType(Cell::VICTORY);
    GL->plateLog();
//    std::cout << "You stepped on a strange slab! The sound of a door opening is heard from the corner\n";
}

PressurePlate* PressurePlate::copy(){
    return new PressurePlate(*this);
}