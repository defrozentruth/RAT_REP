#pragma once

#include "LevelType.hpp"
#include "LevelGenerator.hpp"
#include "../Rules/PlayerSpawnRule.hpp"
#include "../Rules/CoordCellAccessRule.hpp"
#include "../Rules/CoordEventRule.hpp"
#include "../Rules/HorCellAccessLineRule.hpp"
#include "../Rules/RandCellAccessAmountRule.hpp"
#include "../Rules/RandEventAmountRule.hpp"
#include "../Rules/VertCellAccessLineRule.hpp"
#include "../Rules/WinSpawnRule.hpp"





class Field;
class FieldGen;

class FirstLevel : public LevelType{
    LevelGenerator<
        PlayerSpawnRule<0,0>,
        HorCellAccessLineRule<2,0,4>,
        VertCellAccessLineRule<2,0,4>,
        RandEventAmountRule<10>,
        WinSpawnRule<3,3>
    > generator;

public:
    FieldScheme& generate(FieldScheme& scheme);
    FirstLevel() = default;
};