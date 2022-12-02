#include "../PlayerEvent/PlayerEvent.h"

#pragma once

class Enemy: public PlayerEvent{
public:
    Enemy() = default;
    void processEvent(Field *field) final;
    Enemy* copy() override;
};