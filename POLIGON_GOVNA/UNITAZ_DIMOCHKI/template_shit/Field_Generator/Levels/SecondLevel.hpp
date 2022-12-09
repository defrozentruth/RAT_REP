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

class SecondLevel : public LevelType{
    LevelGenerator<
        PlayerSpawnRule<0,0>,
        HorCellAccessLineRule<4, 3, 7>,
        HorCellAccessLineRule<8, 3, 7>,
        VertCellAccessLineRule<3, 5, 9>,
        VertCellAccessLineRule<8, 4, 6>,
        HorCellAccessLineRule<18, 3, 15>,
        HorCellAccessLineRule<14, 14, 18>,
        VertCellAccessLineRule<12, 11, 17>,
        RandEventAmountRule<150>,
        WinSpawnRule<19,19>
    > generator;

public:
    FieldScheme& generate(FieldScheme& scheme);
    SecondLevel() = default;
};