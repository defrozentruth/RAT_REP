#include "../PlayerEvent/PlayerEvent.h"
#include "../../LogType/GameLog.h"

#pragma once

class Heal: public PlayerEvent{
public:
    Heal() = default;
    void processEvent(Field *field, GameLog* GL) final;
    Heal* copy() override;
};