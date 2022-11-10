#include "Field.h"
#include "../LogType/GameLog.h"
#include "../LogType/ErrorLog.h"
#pragma once

class FieldMaker{
public:
    Field read(ErrorLog* EL);
};