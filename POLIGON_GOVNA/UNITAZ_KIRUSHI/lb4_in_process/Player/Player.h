#pragma once

class Player {
    int hp;
    int armor;
    int strength;
public:
    Player(int hp = 100, int armor = 50, int strength = 10);
    int getHp();
    void setHp(int hp);
    int getArmor();
    void setArmor(int armor);
    int getStrength();
    void setStrength(int strength);
    void seeParameters();
};