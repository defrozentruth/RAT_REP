#include "../Player/Player.h"
#include "../Cell/Cell.h"
#include "../Observer/Observer.h"

#pragma once

class Field{
    int y;
    int x;
    Cell** field;
    Player player;
    int ply = 0;
    int plx = 0;
    int flag = 0;
public:
    Field(int y, int x);
    Field(const Field& field);
    void swap(Field& map);
    Field& operator =(const Field& field);
    Field(Field&& field);
    Field& operator =(Field&& field);
    Cell** getField();
    Player& getPlayer();
    int getHeight();
    int getWidth();
    void setFlag(int flag);
    int getFlag();
    void move(int dx, int dy);
};