#include "FileSettingsRead.hpp"
#include <iostream>

FileSettingsRead::FileSettingsRead(){
    LogPool* logger = LogPool::getInstance();
    std::string line;
    std::fstream file("../settings.txt");
    getline(file, line, file.widen('\n'));
    this->associateCmd[line] = Commands::Up;
    
    getline(file, line, file.widen('\n'));
    this->associateCmd[line] = Commands::Left;
    
    getline(file, line, file.widen('\n'));
    this->associateCmd[line] = Commands::Down;
    
    getline(file, line, file.widen('\n'));
    this->associateCmd[line] = Commands::Right;
    
    getline(file, line, file.widen('\n'));
    this->associateCmd[line] = Commands::Finish;
    
}

// void FileSettingsRead::readCommands(){
//     std::string cmd;
//     if(file.is_open()){
//         file << cmd;
//         this->associateCmd[cmd] = Commands::Up;
//         file << cmd;
//         this->associateCmd[cmd] = Commands::Left;
//         file << cmd;
//         this->associateCmd[cmd] = Commands::Down;
//         file << cmd;
//         this->associateCmd[cmd] = Commands::Right;
//         file << cmd;
//         this->associateCmd[cmd] = Commands::Finish;
//     }
// }

std::map <std::string, Commands> FileSettingsRead::getDirections(){
    return this->associateCmd;
}