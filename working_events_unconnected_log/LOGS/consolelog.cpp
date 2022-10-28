#include "consolelog.hpp"
// #include "logpool.hpp"
// #include "gameloggen.hpp"
// #include "infologgen.hpp"
// #include "errorloggen.hpp"

void ConsoleLogger::printLog(){
    for(int i = 0; i < pool.getPool().size(); i++){
        std::cout << pool.getPool()[i] << '\n';
    }
};
LogType ConsoleLogger::retType(){
    return this->type;
};
void ConsoleLogger::newLog(std::string inpLog){
    pool.getPool().push_back(gen->generateMessage(inpLog));
};

ConsoleLogger::ConsoleLogger(LogType type){
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
}