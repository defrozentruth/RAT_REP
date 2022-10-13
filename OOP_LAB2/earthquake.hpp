#ifndef EARTHQUAKE_HPP
#define EARTHQUAKE_HPP

#include "map_events.hpp"
#include "field.hpp"
class Earthquake: public Map_Events{
    public:
        Earthquake() = default;
        void eventProc(void* tmp_field);
        Earthquake* clone() override;
};

#endif