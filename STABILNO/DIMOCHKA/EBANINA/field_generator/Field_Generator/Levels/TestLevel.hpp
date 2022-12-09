#pragma once

#include "LevelType.hpp"
#include "LevelGenerator.hpp"
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

class TestLevel : public LevelType{
    LevelGenerator<
        PlayerSpawnRule<0, 0>,
        WinSpawnRule<0,1>,
        HorCellAccessLineRule<0, 6, 11>,
        CoordCellAccessRule<5,1>,
        CoordCellAccessRule <12,1>,
        HorCellAccessLineRule<2, 4, 5>,
        CoordCellAccessRule<13,2>,
        HorCellAccessLineRule<3, 3,5>,
        CoordCellAccessRule<13,3>,
        HorCellAccessLineRule<4, 3,5>,
        HorCellAccessLineRule<4, 9, 14>,
        HorCellAccessLineRule<5, 2, 4>,
        CoordCellAccessRule<8,5>,
        CoordCellAccessRule<15,5>,
        HorCellAccessLineRule<6,1,3>,
        CoordCellAccessRule<8,6>,
        CoordCellAccessRule<15,6>,
        HorCellAccessLineRule<7,1,3>,
        HorCellAccessLineRule<7,9,14>,
        HorCellAccessLineRule<8,1,3>,
        CoordCellAccessRule<13,8>,
        HorCellAccessLineRule<9,1,3>,
        CoordCellAccessRule<13,9>,
        HorCellAccessLineRule<10,1,3>,
        CoordCellAccessRule<13,10>,
        HorCellAccessLineRule<11,1,3>,
        CoordCellAccessRule<13,11>,
        HorCellAccessLineRule<12,1,5>,
        CoordCellAccessRule<13,12>,
        HorCellAccessLineRule<13,2,6>,
        HorCellAccessLineRule<13,11,13>,
        HorCellAccessLineRule<14,3,13>,
        HorCellAccessLineRule<15,3,6>,
        HorCellAccessLineRule<15,11,13>,
        HorCellAccessLineRule<16,3,6>,
        HorCellAccessLineRule<16,11,13>,
        HorCellAccessLineRule<17,3,6>,
        HorCellAccessLineRule<17,11,13>,
        HorCellAccessLineRule<18,3,6>,
        HorCellAccessLineRule<18,11,13>
    > generator;

public:
    FieldScheme& generate(FieldScheme& scheme);
    TestLevel() = default;
};