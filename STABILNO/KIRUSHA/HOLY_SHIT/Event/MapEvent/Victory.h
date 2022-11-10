#include "../MapEvent/MapEvent.h"
#include "../../LogType/GameLog.h"

#pragma once

class Victory: public MapEvent{
    GameLog* GL;
public:
    Victory() = default;
    void processEvent(Field *field, GameLog* GL) final;
    Victory* copy() override;
};