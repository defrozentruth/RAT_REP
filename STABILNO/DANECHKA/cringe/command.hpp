#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>

class CommandReader{
private:
    char command;
public:
    void readCommand();
    char getCommand() const;
};

#endif