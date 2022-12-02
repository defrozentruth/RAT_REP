#pragma once

#include "../FieldScheme.hpp"

enum Level{
    First, Second
};

class LevelType{
public:
    virtual FieldScheme& generate(FieldScheme& scheme) = 0;
};