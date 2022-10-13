#ifndef WIN_HPP
#define WIN_HPP

#include "map_events.hpp"

class Win: public Map_Events{
    int score;
public:
    Win(int score = 100):score(score){};
    void eventProc(void* tmp_player);
    Win* clone() override;
};

#endif