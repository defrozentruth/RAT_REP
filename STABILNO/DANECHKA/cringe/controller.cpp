#include "controller.hpp"

void Controller::getCommand(char command){
    if(control_scheme.find(command) != control_scheme.end()){
        this->command = control_scheme.at(command);
    }
}