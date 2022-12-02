#pragma once

#include <fstream>
#include <map>
#include <string>
#include "../Logs/LogPool.hpp"

enum Commands{
    Up,
    Left,
    Down,
    Right,
    Finish
};

class FileSettingsRead{
    std::map<std::string, Commands> associateCmd{};
    void setDefault();
public:
    FileSettingsRead();
    std:: map<std::string, Commands> getDirections();
};