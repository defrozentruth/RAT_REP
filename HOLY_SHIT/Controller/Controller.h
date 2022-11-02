#include "../Field/Field.h"
#include "../GameLog/GameLog.h"
#include "../ErrorLog/ErrorLog.h"
#pragma once

class Controller{
public:
    void process(char command, Field& field, GameLog* GL, ErrorLog* EL);
};
