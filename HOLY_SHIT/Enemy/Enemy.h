#include "../PlayerEvent/PlayerEvent.h"
#include "../GameLog/GameLog.h"

#pragma once

class Enemy: public PlayerEvent{
public:
    Enemy() = default;
    void processEvent(Field *field, GameLog* GL) final;
    Enemy* copy() override;
};