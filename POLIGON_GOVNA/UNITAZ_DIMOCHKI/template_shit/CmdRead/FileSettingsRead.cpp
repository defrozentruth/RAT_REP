#include "FileSettingsRead.hpp"
#include <iostream>

FileSettingsRead::FileSettingsRead(){
    std::string line;
    std::fstream file("../settings.txt");
    if(file.is_open()){
        bool err = false;
        file >> line;
        if(err == false){
                if (associateCmd.find(line) == associateCmd.end())
                associateCmd.insert(std::pair<std::string, Commands>(line, Up));
            else{
                setDefault();
                err = true;
            };
        }
        file >> line;
        if(err == false){
                if (associateCmd.find(line) == associateCmd.end())
                associateCmd.insert(std::pair<std::string, Commands>(line, Left));
            else{
                setDefault();
                err = true;
            };
        }
        file >> line;
        if(err == false){
                if (associateCmd.find(line) == associateCmd.end())
                associateCmd.insert(std::pair<std::string, Commands>(line, Down));
            else{
                setDefault();
                err = true;
            };
        }
        file >> line;
        if(err == false){
                if (associateCmd.find(line) == associateCmd.end())
                associateCmd.insert(std::pair<std::string, Commands>(line, Right));
            else{
                setDefault();
                err = true;
            };
        }
        file >> line;
        if(err == false){
                if (associateCmd.find(line) == associateCmd.end())
                associateCmd.insert(std::pair<std::string, Commands>(line, Finish));
            else{
                setDefault();
                err = true;
            };
        }
        if(associateCmd.size() < 5){
            setDefault();
        }
    }else{
        LogPool::getInstance()->printLog(Error, "Error while reading settings file\n");
        exit(1);
    }
}
std::map <std::string, Commands> FileSettingsRead::getDirections(){
    return this->associateCmd;
}

void FileSettingsRead::setDefault(){
    LogPool::getInstance()->printLog(Error, "Bad settings. Loading standart settings\n");
        associateCmd.insert(std::pair<std::string, Commands>("w", Up));
        associateCmd.insert(std::pair<std::string, Commands>("a", Left));
        associateCmd.insert(std::pair<std::string, Commands>("s", Down));
        associateCmd.insert(std::pair<std::string, Commands>("d", Right));
        associateCmd.insert(std::pair<std::string, Commands>("X", Finish));
}