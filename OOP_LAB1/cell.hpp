#include "event.hpp"
#include <utility>

#pragma once

class Cell{
    bool access;
    bool playerOn;
    Event* event;
    public:
        Cell(bool access = true, bool playerOn = false, Event* event = nullptr);
        Cell(Cell& obj):access(obj.access), event(obj.event){};
        void swap(Cell &obj);
        Cell& operator=(Cell& obj);
        void changeEvent(Event* event);
        void changeAccess(bool new_access);
        bool isPassable();
        void playerVisit();
};