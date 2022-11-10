#include "../Field/Field.h"
#include "../LogType/GameLog.h"
#include "../LogType/ErrorLog.h"
#pragma once

class Controller{
public:
    void process(char command, Field& field, GameLog* GL, ErrorLog* EL);
};
