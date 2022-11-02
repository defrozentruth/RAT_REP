#include "../GameLog/GameLog.h"
#pragma once

class Field;

class Event{
public:
    virtual Event* copy() = 0;
    virtual void processEvent(Field *field, GameLog* GL) = 0;
};