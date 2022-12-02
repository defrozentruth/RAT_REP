#pragma once
#include "Strategy.h"

class MediumLevel: public Strategy{
public:
    Field* create() override;
};