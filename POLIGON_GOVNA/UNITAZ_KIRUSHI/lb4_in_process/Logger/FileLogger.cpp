#include "FileLogger.h"

FileLogger::FileLogger(const std::string &name){
    file.open(name, std::ios::out);
}

void FileLogger::print(Message *msg){
    file << msg;
    file.flush();
}

FileLogger::~FileLogger(){
    file.close();
}