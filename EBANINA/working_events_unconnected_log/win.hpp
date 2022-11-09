#ifndef WIN_HPP
#define WIN_HPP

#include "player_events.hpp"

class Win: public Player_Events{
    int score;
protected:
    Player* player;
public:
    Win(Player* player, int score = 100):player(player), score(score){};
    void eventProc();
    Win* clone() override;
};

#endif