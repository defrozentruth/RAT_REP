#include "Mediator.h"

void Mediator::execute(Field* field, FieldView& printer){
    char chr;
    Observer* obs = Observer::get();
    std::map<char, Control::Moveset> command = ctrl->getCommands();
    chr = reader->read(ctrl);
    system("cls");
    while(command.at(chr) != Control::QUIT){
        if (command.at(chr) != Control::QUIT) {
            ctrl->process(command.at(chr), field);
            if (field->getFlag() < 0 || field->getFlag() > 0) {
                break;
            }
            printer.printField(field);
            field->getPlayer().seeParameters();
        }
        chr = reader->read(ctrl);
        system("cls");
    }
}