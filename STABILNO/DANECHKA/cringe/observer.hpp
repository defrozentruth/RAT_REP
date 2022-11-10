#pragma once
#include <string>

class Observer{
public:
    virtual void update(std::string msg) = 0;
};