#include "filelog.hpp"

FileLogger::FileLogger(const std::string& name){
    file.open(name, std::ios_base::out | std::ios_base::app);
};

void FileLogger::printLog(){
    for(int i = 0; i < this->pool.getPool().size(); i++){
        file << this->pool.getPool()[i] << '\n';
    }
}

LogType FileLogger::retType(){
    return this->type;
};
void FileLogger::newLog(std::string inpLog){
    pool.getPool().push_back(gen.generateMessage(inpLog));
};