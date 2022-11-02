#include "../Field/Field.h"
#include "../GameLog/GameLog.h"
#include "../ErrorLog/ErrorLog.h"
#pragma once

class FieldMaker{
public:
    Field read(ErrorLog* EL);
};