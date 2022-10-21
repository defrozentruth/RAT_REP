#ifndef WIN_HPP
#define WIN_HPP

#include "map_events.hpp"

class Win: public Map_Events{
    int score;
public:
    Win(int score = 100):score(score){};
    void eventProc(Field& field);
    Win* clone() override;
};

#endif