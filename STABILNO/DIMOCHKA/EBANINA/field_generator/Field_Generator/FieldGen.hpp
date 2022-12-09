#pragma once

#include "../Map_Player/field.hpp"
#include "Levels/LevelType.hpp"
#include "Levels/LevelGenerator.hpp"
#include "Levels/FirstLevel.hpp"
#include "Levels/SecondLevel.hpp"
#include "Levels/TestLevel.hpp"
#include "FieldScheme.hpp"

class FieldGen {
private:
    Level level;
    LevelType* type;
    FieldScheme scheme;
    void execute(Field &field);
    void setRandEvent(Field* field, int x, int y);
    void setScheme();
public:
    FieldGen() = default;
    void setLevel(Level level);
    Field* create();
    ~FieldGen();
};