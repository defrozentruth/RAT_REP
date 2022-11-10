#include <iostream>
#include "Controller.h"


void Controller::process(char command, Field& field, GameLog* GL, ErrorLog* EL){
    switch(command) {
        case 'w':
            field.move(0, -1, GL, EL);
            break;
        case 'a':
            field.move(-1, 0, GL, EL);
            break;
        case 's':
            field.move(0, 1, GL, EL);
            break;
        case 'd':
            field.move(1, 0, GL, EL);
            break;
        default:
            std::cout << "Invalid command!\n";
            break;
    }
}