#include "../Event/Event.h"

#pragma once

class Cell{
public:
    enum cell_type{
        PASSABLE,
        IMPASSABLE,
        ACTIVE,
        HEAL,
        ENEMY,
        PLATE,
        VICTORY
    };
    Cell(cell_type = PASSABLE, Event* ev = nullptr);
    Cell& operator =(const Cell& cell);
    cell_type getType();
    void setType(cell_type type);
    void changeEvent(Event* ev);
    Event* getEvent();
private:
    Event* ev;
    cell_type type;
};