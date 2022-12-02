#pragma once

#include "LevelType.hpp"
#include "LevelGenerator.hpp"
#include "../Rules/CellAccessRule.hpp"
#include "../Rules/EnemyRule.hpp"
#include "../Rules/OverseerRule.hpp"
#include "../Rules/PlayerSpawnRule.hpp"
#include "../Rules/SledgeRule.hpp"
#include "../Rules/TrapRule.hpp"
#include "../Rules/WinRule.hpp"

class Field;
class FieldGen;

class FirstLevel : public LevelType{
    LevelGenerator<
        CellAccessRule<10>,
        EnemyRule<5>,
        OverseerRule<1>,
        PlayerSpawnRule<2, 2>,
        SledgeRule<1>,
        TrapRule<2>,
        WinRule<4,4>
    > generator;

public:
    FieldScheme& generate(FieldScheme& scheme);
    FirstLevel() = default;
};