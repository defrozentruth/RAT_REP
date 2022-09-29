#include "mediator.hpp"

void Mediator::notifyCommandReader(){
        cr.readCommand();
    }
void Mediator::notifyController(){
    control.getCommand(cr.getCommand());
}
Player::direction Mediator::getControllerCommand(){
    return control.command;
}