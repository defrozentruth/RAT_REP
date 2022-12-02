#pragma once

#include <map>
#include <string>
#include "ICmdRead.hpp"
#include "FileSettingsRead.hpp"

class ConsoleCmdRead: public CmdRead{
    bool exitState;
    std::map<std::string, Commands> cmds;

public:
    ConsoleCmdRead(std::map<std::string, Commands> cmds, bool exitState = false):exitState(exitState), cmds(cmds){};
    bool getExitState();
    Commands readCmd();
};