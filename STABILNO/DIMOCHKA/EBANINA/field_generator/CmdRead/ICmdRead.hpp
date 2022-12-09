#pragma once
#include "FileSettingsRead.hpp"

class CmdRead{
public:
    virtual Commands readCmd() = 0;
};