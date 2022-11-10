#include "consolelog.hpp"

void ConsoleLogger::printLog(){
    for(int i = 0; i < pool.getPool().size(); i++){
        std::cout << pool.getPool()[i] << '\n';
    }
};
LogType ConsoleLogger::retType(){
    return this->type;
};
void ConsoleLogger::newLog(std::string inpLog){
    pool.getPool().push_back(gen.generateMessage(inpLog));
};