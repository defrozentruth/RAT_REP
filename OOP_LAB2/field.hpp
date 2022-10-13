#ifndef FIELD_HPP
#define FIELD_HPP

#include <iostream>
#include <utility>
#include "cell.hpp"
#include "win.hpp"
#include "overseer.hpp"
#include "enemy.hpp"
#include "trap.hpp"
#include "earthquake.hpp"

#define BASE_VALUE 10

class Player;

class Field{
    Cell** map;
    int size_x;
    int size_y;
    int player_x;
    int player_y;
    public:
        Field(int x = BASE_VALUE, int y = BASE_VALUE, int player_x = 0, int player_y = 0);
        void movePlayer(int x, int y, Player& player);
        Cell** getField();
        int getHeight();
        int getWidth();
        int getPlayerX();
        int getPlayerY();
        Field(const Field& fieldObj);
        void swap(Field &fieldObj);
        Field& operator=(const Field& fieldObj);
        Field(Field&& fieldObj);
        Field& operator=(Field&& filedObj);
        
};

#endif