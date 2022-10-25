#ifndef EARTHQUAKE_HPP
#define EARTHQUAKE_HPP

#include "map_events.hpp"

class Earthquake: public Map_Events{
    Field* field;
    public:
        Earthquake(Field* field):field(field){};
        void eventProc();
        Earthquake* clone() override;
};

#endif