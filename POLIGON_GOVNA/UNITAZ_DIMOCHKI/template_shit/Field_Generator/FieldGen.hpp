#pragma once

#include "../Map_Player/field.hpp"
#include "Levels/LevelType.hpp"
#include "Levels/LevelGenerator.hpp"
#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"
#include "FieldScheme.hpp"

class FieldGen {
private:
    Level level;
    LevelType* type;
    FieldScheme scheme;

public:
    FieldGen() = default;
    void execute(Field &field);
    void setType(LevelType* type);
    void setLevel(Level level);
    void setScheme();
    Field* create();
    ~FieldGen();
};