#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Iplayer_event.hpp"
#include "field.hpp"

class Enemy: public Iplayer_event{

public:    
    Enemy(Player* player, Field* field, int power = 30, int hp = 70):player(player),field(field), _power(power), _hp(hp){};
    void change_state() override;
    
    Enemy* clone() override;

private:
    int _power;
    int _hp;

    const int points_for_kill = 25;

    void attack();
    void defence();
    void goToEmptyCell(int old_x, int old_y);

protected:
    Player* player;
    Field* field;
};


#endif