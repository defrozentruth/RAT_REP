#include "../MapEvent/MapEvent.h"

#pragma once

class Victory: public MapEvent{
public:
    Victory() = default;
    void processEvent(Field *field) final;
    Victory* copy() override;
};