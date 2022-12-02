#pragma once
#include "Strategy.h"

class HardLevel: public Strategy{
public:
    Field* create() override;
};