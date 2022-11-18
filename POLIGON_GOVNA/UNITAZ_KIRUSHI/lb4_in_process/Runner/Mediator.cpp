#include "Mediator.h"

void Mediator::execute(Field& field, FieldView& printer){
    char chr;
    chr = reader->read();
    system("cls");
    while(ctrl->command.at(chr) != Control::QUIT){
        ctrl->process(ctrl->command.at(chr), field);
        if(field.getFlag() < 0 || field.getFlag()>0){
            break;
        }
        printer.printField(field);
        field.getPlayer().seeParameters();
        chr = reader->read();
        system("cls");
    }
}