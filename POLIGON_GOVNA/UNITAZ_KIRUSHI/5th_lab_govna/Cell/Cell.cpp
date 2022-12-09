#include "Cell.h"

Cell::Cell(cell_type type, Event* ev):type(type), ev(ev){}

Cell& Cell::operator =(const Cell& cell){
    if(this != &cell){
        type = cell.type;
        ev = cell.ev->copy();
    }
    return *this;
}

Cell::cell_type Cell::getType(){
    return Cell::type;
}

void Cell::setType(Cell::cell_type type){
    this->type = type;
}

void Cell::changeEvent(Event* ev){
    if(ev != nullptr)
        this->ev = ev->copy();
    else
        this->ev = nullptr;
}

Event* Cell::getEvent(){
    if (this->ev != nullptr) return this->ev;
    return nullptr;
}