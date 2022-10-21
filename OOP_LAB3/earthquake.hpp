#ifndef EARTHQUAKE_HPP
#define EARTHQUAKE_HPP

#include "map_events.hpp"

class Earthquake: public Map_Events{
    public:
        Earthquake() = default;
        void eventProc(Field& field);
        Earthquake* clone() override;
};

#endif