#include "win.hpp"

void Win::change_state(){
    field->changeState(Field::WIN);
    //this->notify();
}

Win* Win::clone(){
    return new Win(*this);
}