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
        std::cout << "!" << cmd << "!\n";
    }while(cmds.find(cmd) == cmds.end());
    if(cmds.at(cmd) == Finish){
        this->exitState = true;
    }
    std::cout << "aaaaaaaaa\n";
    return cmds.at(cmd);
    // std::string cmd;
    // std::cin >> cmd;
    // if(cmds.find(cmd) != cmds.end())
    //     return cmds.at(cmd);
    // else
    //     return Commands::Finish;
}