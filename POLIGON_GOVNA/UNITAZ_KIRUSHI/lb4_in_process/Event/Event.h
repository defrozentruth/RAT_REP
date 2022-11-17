#pragma once

class Field;

class Event{
public:
    virtual Event* copy() = 0;
    virtual void processEvent(Field *field) = 0;
};