#ifndef FIELD_HPP
#define FIELD_HPP

#include <iostream>
#include <utility>
#include "cell.hpp"
#include "../Events/Player_Events/win.hpp"
#include "../Events/Player_Events/overseer.hpp"
#include "../Events/Player_Events/enemy.hpp"
#include "../Events/Player_Events/trap.hpp"
#include "../Events/Map_Events/earthquake.hpp"
#include "../Events/Map_Events/sledge.hpp"
#include "player.hpp"
#include "../Logs/LogPool.hpp"

#define BASE_VALUE 10


class Field{
    Cell** map;
    int size_x;
    int size_y;
    int player_x;
    int player_y;
    Player* player;
    public:
        Field(int x = BASE_VALUE, int y = BASE_VALUE);
        void movePlayer(int x, int y);
        Cell** getField();
        int getHeight();
        int getWidth();
        int getPlayerX();
        int getPlayerY();
        void setPlayerX(int x);
        void setPlayerY(int y);
        Player* getPlayer();
        Field(const Field& fieldObj);
        void swap(Field &fieldObj);
        Field& operator=(const Field& fieldObj);
        Field(Field&& fieldObj);
        Field& operator=(Field&& filedObj);
        
};

#endif