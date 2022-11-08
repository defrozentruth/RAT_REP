#ifndef SLEDGE_HPP
#define SLEDGE_HPP

#include "map_events.hpp"
#include "LogPool.hpp"

class Sledge: public Map_Events{
    Field* field;
    public:
        Sledge(Field* field):field(field){};
        void eventProc();
        Sledge* clone() override;
};

#endif