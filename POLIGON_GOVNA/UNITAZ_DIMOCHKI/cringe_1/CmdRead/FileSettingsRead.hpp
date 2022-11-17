#include <fstream>
#include <map>
#include <string>
#include "../Logs/LogPool.hpp"

#pragma once

enum Commands{
    Up,
    Left,
    Down,
    Right,
    Finish
};

class FileSettingsRead{
    std::map<std::string, Commands> associateCmd{};
public:
    FileSettingsRead();
    std:: map<std::string, Commands> getDirections();
};