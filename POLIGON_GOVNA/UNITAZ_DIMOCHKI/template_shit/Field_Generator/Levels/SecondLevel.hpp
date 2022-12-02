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

class SecondLevel : public LevelType{
    LevelGenerator<
        CellAccessRule<20>,
        EnemyRule<10>,
        OverseerRule<3>,
        PlayerSpawnRule<5, 4>,
        SledgeRule<3>,
        TrapRule<10>,
        WinRule<1,1>
    > generator;

public:
    FieldScheme& generate(FieldScheme& scheme);
    SecondLevel() = default;
};