#include "../MapEvent/MapEvent.h"

#pragma once

class PressurePlate: public MapEvent{
public:
    PressurePlate() = default;
    void processEvent(Field *field) final;
    PressurePlate* copy() override;
};