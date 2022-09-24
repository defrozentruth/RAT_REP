#include "mediator.hpp"

void Mediator::notifyCommandReader(){
        cr.setCommand();
    }
void Mediator::notifyController(){
    control.getCommand(cr.getCommand());
}
direction Mediator::getControllerCommand(){
    return control.command;
}