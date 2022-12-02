#include "ConsoleCmdRead.hpp"
#include <iostream>
#include <string>
#include <map>

bool ConsoleCmdRead::getExitState(){
    return exitState;
};

Commands ConsoleCmdRead::readCmd(){
    std::string cmd;
    do{
        std::cin >> cmd;
    }while(cmds.find(cmd) == cmds.end());
    if(cmds.at(cmd) == Finish){
        this->exitState = true;
    }
    return cmds.at(cmd);
}