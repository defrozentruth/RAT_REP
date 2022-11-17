#include "Victory.h"
#include "../../Field/Field.h"
#include <iostream>
#include <windows.h>

void Victory::processEvent(Field *field, GameLog* GL){
    GL->winLog();
//    std::cout << "You found a way out and got out of the dungeon!\n";
    field->setFlag(1);
}

Victory* Victory::copy(){
    return new Victory(*this);
}