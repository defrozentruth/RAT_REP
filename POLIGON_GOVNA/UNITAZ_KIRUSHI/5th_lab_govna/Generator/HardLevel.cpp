#include "HardLevel.h"

Field* HardLevel::create(){
    FieldGenerator<WallRule<20>,
            HealRule<30>,
            EnemyRule<100>,
            ArmorRule<3>,
            PlayerRule<0,0>,
            PlateRule<10>> generator;
    return generator.generate(20, 20);
}