#include "Control.h"

Control::Control(){
    std::ifstream in;
    in.open("settings");
    std::string flag;
    char bind;
    if (in.is_open())
    {
        while (in >> flag >> bind)
        {
            if(flags.find(flag) != flags.end()){
                command.insert(std::make_pair(bind, flags.at(flag)));
            }
        }
    }
    in.close();
}

void Control::process(Moveset command, Field &field){
    switch(command) {
        case Moveset::UP:
            field.move(0, -1);
            break;
        case Moveset::LEFT:
            field.move(-1, 0);
            break;
        case Moveset::DOWN:
            field.move(0, 1);
            break;
        case Moveset::RIGHT:
            field.move(1, 0);
            break;
        default:
            std::cout << "Invalid command!\n";
            break;
    }
}