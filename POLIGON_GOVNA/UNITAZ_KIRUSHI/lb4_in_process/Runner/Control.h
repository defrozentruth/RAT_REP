#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "../Field/Field.h"
#pragma once

class Control{
public:
    enum Moveset{
        UP,
        LEFT,
        DOWN,
        RIGHT,
        QUIT
    };
    std::map<char, Moveset> command;
    Control();
    void process(Moveset command, Field& field);
private:
    std::map<std::string, Moveset> flags{
            {"up", UP},
            {"left", LEFT},
            {"down", DOWN},
            {"right", RIGHT},
            {"quit", QUIT},
    };
};