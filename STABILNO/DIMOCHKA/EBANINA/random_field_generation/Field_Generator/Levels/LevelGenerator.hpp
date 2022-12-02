#pragma once

#include "../FieldScheme.hpp"

template<typename ... Rules>
class LevelGenerator{
    private:
        template<typename Rule>
        void applyRule(FieldScheme& scheme){
            Rule rule;
            rule.update(scheme);
        }
    public:
        FieldScheme& generate(FieldScheme& scheme){
            (applyRule<Rules>(scheme), ...);
            return scheme;
        }
};