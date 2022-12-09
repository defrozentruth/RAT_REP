#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../Map_Player/field.hpp"
#include <iostream>
#include "../CmdRead/FileSettingsRead.hpp"

class Controller{
    public:
        void mover(Commands cmd, Field& field);
};

#endif