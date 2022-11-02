#include "../MapEvent/MapEvent.h"
#include "../GameLog/GameLog.h"

#pragma once

class PressurePlate: public MapEvent{
public:
    PressurePlate() = default;
    void processEvent(Field *field, GameLog* GL) final;
    PressurePlate* copy() override;
};