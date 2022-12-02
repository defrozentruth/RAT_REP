#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
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
    Control();
    std::map<char, Moveset> getCommands();
    void setDefault();
    void process(Moveset command, Field* field);
private:
    std::map<char, Moveset> command;
    std::map<std::string, Moveset> flags{
            {"up", UP},
            {"left", LEFT},
            {"down", DOWN},
            {"right", RIGHT},
            {"quit", QUIT},
    };
};