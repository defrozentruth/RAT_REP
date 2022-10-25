#ifndef FIELD_HPP
#define FIELD_HPP

#include <iostream>
#include "cell.hpp"
#include "player.hpp"


class Field{

public:

    enum game_state{
        DEFAULt,
        LOSE,
        WIN
    };
    
    Field(int height = 10, int width = 10, int x_pos = 0, int y_pos = 0);
    Field(const Field& obj);
    Field& operator=(const Field& obj);
    Field(Field&& obj);
    Field& operator=(Field&& obj);
    ~Field();

    int height() const;
    
    int width() const;
    
    Cell** getField();

    void setPlayerPosition(int x, int y);

    int player_x() const;

    int player_y() const;

    void move(Player::direction dir);

    Player* getPlayer();

    void changeState(game_state state);

    game_state getState() const;

    void react();

private:
    int _height;
    int _width;
    int x_pos;
    int y_pos;
    Cell** _game_field;
    Player player;
    game_state state;

};

#endif