#pragma once

#include "../FieldScheme.hpp"

template<int X, int Y>
class FieldSizeRule{
public:
    void update(FieldScheme& scheme){
        scheme.getMask().resize(Y);
        for (auto& row : scheme.getMask()){
            row.resize(X);
        }
    }
};