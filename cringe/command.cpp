#include "command.hpp"

void CommandReader::setCommand(){
        std::cin >> this->command;
    }

char CommandReader::getCommand() const{
        return this->command;
    }