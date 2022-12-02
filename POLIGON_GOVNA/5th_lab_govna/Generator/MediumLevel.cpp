#include "MediumLevel.h"

Field* MediumLevel::create(){
    FieldGenerator<WallRule<20>,
            HealRule<5>,
            EnemyRule<10>,
            ArmorRule<3>,
            PlayerRule<0,0>,
            PlateRule<4>> generator;
    return generator.generate(10, 10);
}