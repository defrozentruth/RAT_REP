#include "../Runner/CommandReader.h"
#include "../Runner/Control.h"
#include "../Field/FieldView.h"
#pragma once

class Mediator{
    Control* ctrl;
    CommandReader* reader;
public:
    Mediator(Control* ctrl, CommandReader* reader):ctrl(ctrl), reader(reader){}
    void execute(Field& field, FieldView& printer);
};