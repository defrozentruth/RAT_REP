#include "FileLog.hpp"

    FileLog::FileLog(std::string name){
        file.open(name, std::ios::out);

    }
    FileLog::~FileLog(){
        file.close();
    }

    void FileLog::output(Message* msg){
            //file.open("log.txt", std::ofstream::out | std::ofstream::trunc);
            // std::cout << "Trying to log in file\n";
            file << *msg << '\n'; 
            file.flush();
            //file.close();
    }
