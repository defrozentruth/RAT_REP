#include "command.hpp"

void CommandReader::readCommand(){
        std::cin >> this->command;
    }

char CommandReader::getCommand() const{
        return this->command;
    }