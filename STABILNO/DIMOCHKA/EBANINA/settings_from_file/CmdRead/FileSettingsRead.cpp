#include "FileSettingsRead.hpp"
#include <iostream>

FileSettingsRead::FileSettingsRead(){
    LogPool* logger = LogPool::getInstance();
    std::string line;
    std::fstream file("../settings.txt");
    if(file.is_open()){
        file >> line;
        associateCmd.insert(std::pair<std::string, Commands>(line, Up));
        file >> line;
        associateCmd.insert(std::pair<std::string, Commands>(line, Left));
        file >> line;
        associateCmd.insert(std::pair<std::string, Commands>(line, Down));
        file >> line;
        associateCmd.insert(std::pair<std::string, Commands>(line, Right));
        file >> line;
        associateCmd.insert(std::pair<std::string, Commands>(line, Finish));
    }else{
        logger->printLog(Error, "Error while reading settings file\n");
        exit(1);
    }
}
std::map <std::string, Commands> FileSettingsRead::getDirections(){
    return this->associateCmd;
}