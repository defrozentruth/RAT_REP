#pragma once

#include "../FieldScheme.hpp"

enum Level{
    First, Second, Test
};

class LevelType{
public:
    virtual FieldScheme& generate(FieldScheme& scheme) = 0;
};