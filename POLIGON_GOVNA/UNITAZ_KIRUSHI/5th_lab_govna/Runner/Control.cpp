#include "Control.h"

void Control::setDefault(){
    Observer* obs = Observer::get();
    obs->notify(Message::Error, "Incorrect control format!\n");
    obs->notify(Message::Info, "Default moveset will be called\n");
    command = std::map<char, Moveset>{
            {'w', UP},
            {'a', LEFT},
            {'s', DOWN},
            {'d', RIGHT},
            {'x', QUIT},
    };
    obs->notify(Message::Info, "Moveset is set on: WASD\n");
}

Control::Control(){
    std::ifstream in;
    Observer* obs = Observer::get();
    std::vector<std::string> check;
    in.open("settings");
    std::string flag;
    char bind;
    if(in.is_open())
    {
        obs->notify(Message::Info, "Movement is set on:\n");
        while (in >> flag >> bind)
        {
            if(flags.find(flag) != flags.end()){
                auto it = std::find(check.begin(), check.end(), flag);
                if(command.find(bind) != command.end() || it != check.end()){
                    setDefault();
                    break;
                }
                command.insert(std::make_pair(bind, flags.at(flag)));
                check.push_back(flag);
                obs->notify(Message::Info, "\t" + flag + " " + bind + "\n");
            }
        }
        if(command.size() != 5){
            setDefault();
        }
    }
    else{
        obs->notify(Message::Error, "Non-existent file!\n");
        setDefault();
    }
    in.close();
}

std::map<char, Control::Moveset> Control::getCommands(){
    return command;
}

void Control::process(Moveset command, Field* field){
    switch(command) {
        case Moveset::UP:
            field->move(0, -1);
            break;
        case Moveset::LEFT:
            field->move(-1, 0);
            break;
        case Moveset::DOWN:
            field->move(0, 1);
            break;
        case Moveset::RIGHT:
            field->move(1, 0);
            break;
        default:
            std::cout << "Invalid command!\n";
            break;
    }
}