#ifndef EXECUTE_HPP
#define EXECUTE_HPP

#include <iostream>
#include "../Map_Player/field.hpp"
#include "controller.hpp"
#include "fieldview.hpp"
#include "../Logs/LogPool.hpp"
#include "../CmdRead/FileSettingsRead.hpp"
#include "../CmdRead/ConsoleCmdRead.hpp"

class Execute{
public:
    void run();
};

#endif