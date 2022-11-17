#pragma once

#include <map>
#include <string>
#include <utility>
#include "ICmdRead.hpp"
#include "FileSettingsRead.hpp"

class ConsoleCmdRead : public CmdRead {
    bool exitState;
    std::map<std::string, Commands> cmds;

public:
    explicit ConsoleCmdRead(std::map<std::string, Commands> cmds, bool exitState = false)
        : exitState(exitState), cmds(std::move(cmds)){};
    bool getExitState() const;
    Commands readCmd() override;
};
