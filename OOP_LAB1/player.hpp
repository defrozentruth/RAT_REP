#pragma once

class Player{
    int hp;
    int armor;
    int agility;
    public:
        Player(int hp = 10, int armor = 1, int agility = 1);
        void setHP(int hp);
};