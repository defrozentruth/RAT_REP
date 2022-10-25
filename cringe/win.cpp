#include "win.hpp"

void Win::change_state(){
    field->changeState(Field::WIN);
    // std::cout << "you win!!!\n";
}

Win* Win::clone(){
    return new Win(*this);
}