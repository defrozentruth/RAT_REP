#include "cell.hpp"

Cell& Cell::operator=(const Cell& cell){
    if(this != &cell){
        type = cell.type;
        event = cell.event->clone();
    }
    return *this;
}

Cell::~Cell(){
    delete event;
}

void Cell::react(Player& player){
    this->type = PUSHED;
    if(event != nullptr){
        event->change_state(player);
    }
}

void Cell::setDefault(){
    event = nullptr;
    this->type = DEFAULT;
}

void Cell::setImpassable(){
    type = IMPASSABLE;
}

void Cell::setEvent(Event* event){
    this->event = event->clone();
    type = EVENT;
}

Cell::cell_type Cell::getType(){
    return type;
}