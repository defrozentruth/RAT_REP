#include "event.hpp"

#pragma once

class Cell{
    int x;
    int y;
    bool access;
    bool playerOn;
    Event* event;
    public:
        Cell(int x = 0, int y = 0, bool access = true, bool playerOn = false, Event* event = nullptr);
        Cell(Cell& obj):x(obj.x), y(obj.y), access(obj.access), event(obj.event){};
        Cell& operator =(Cell& obj);
        void accessChanger(bool access);
        void changeEvent(Event* event);
        void changeAccess(bool new_access);
        bool isPassable();
        void playerVisit();
};