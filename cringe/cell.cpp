#include "cell.hpp"

Cell& Cell::operator=(const Cell& cell){
    if(this != &cell){
        _is_passable = cell._is_passable;
        _is_pushed = cell._is_pushed;
        event = cell.event;
    }
    return *this;
}

bool Cell::getIsPushed() const{
    return this->_is_pushed;
}

bool Cell::getIsPassable() const{
    return this->_is_passable;
}

void Cell::react(){
    this->_is_pushed = true;
}

void Cell::setDefault(){
    this->_is_pushed = false;
}

void Cell::setImpassable(){
    _is_passable = false;
}
