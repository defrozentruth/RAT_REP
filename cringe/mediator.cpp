#include "mediator.hpp"

void Mediator::notifyCommandReader(){
        cr.readCommand();
        control.getCommand(cr.getCommand());
    }
// void Mediator::notifyController(){
    
// }
Player::direction Mediator::getControllerCommand(){
    return control.command;
}