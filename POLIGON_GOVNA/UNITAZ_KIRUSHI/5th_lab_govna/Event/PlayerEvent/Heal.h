#include "../PlayerEvent/PlayerEvent.h"

#pragma once

class Heal: public PlayerEvent{
public:
    Heal() = default;
    void processEvent(Field *field) final;
    Heal* copy() override;
};