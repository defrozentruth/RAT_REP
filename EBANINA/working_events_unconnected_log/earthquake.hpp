#ifndef EARTHQUAKE_HPP
#define EARTHQUAKE_HPP

#include "map_events.hpp"

class Earthquake: public Map_Events{
    Field* field;
    void checkLeft(int x, int y);
    void checkRight(int x, int y);
    void checkDown(int x, int y);
    public:
        Earthquake(Field* field):field(field){};
        void eventProc();
        Earthquake* clone() override;
};

#endif