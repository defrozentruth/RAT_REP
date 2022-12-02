#include <iostream>
#include "Control.h"
#pragma once

class CommandReader{
public:
    virtual char read(Control* ctrl) = 0;
};