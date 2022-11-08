#include "filelog.hpp"
// #include "logpool.hpp"
// #include "gameloggen.hpp"
// #include "infologgen.hpp"
// #include "errorloggen.hpp"

FileLogger::FileLogger(LogType type,const std::string& name){
    file.open(name, std::ios_base::out | std::ios_base::app);
    this->type = type;
    if (type == LogType::Error){
        gen = new ErrorLogGenerator();
    }
    if (type == LogType::Game){
        gen = new GameLogGenerator();
    }
    if (type == LogType::Info){
        gen = new InfoLogGenerator();
    }
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
    pool.getPool().push_back(gen->generateMessage(inpLog));
};