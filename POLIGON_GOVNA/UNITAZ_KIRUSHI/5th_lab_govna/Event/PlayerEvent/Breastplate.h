#include "../PlayerEvent/PlayerEvent.h"
#pragma once

class Breastplate: public PlayerEvent{
public:
    Breastplate() = default;
    void processEvent(Field *field) final;
    Breastplate* copy() override;
};