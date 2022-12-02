#include "CommandReader.h"
#pragma once

class ConsoleReader: public CommandReader{
public:
    char read(Control* ctrl) override;
};