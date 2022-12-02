#pragma once
#include "../Field/Field.h"
#include "FieldGenerator.h"

class Strategy{
public:
    virtual Field* create() = 0;
};