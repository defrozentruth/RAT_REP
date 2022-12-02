#include "ConsoleReader.h"

char ConsoleReader::read(Control* ctrl){
    char com;
    std::map<char, Control::Moveset> commands = ctrl->getCommands();
    do {
        std::cin >> com;
    }while(commands.find(com) == commands.end());
    return com;
}