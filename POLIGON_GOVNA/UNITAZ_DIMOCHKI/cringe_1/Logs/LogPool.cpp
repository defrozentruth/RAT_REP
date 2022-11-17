#include "LogPool.hpp"

void LogPool::addStream(std::string type){
    if (type == "console")
        this->pool.push_back(new ConsoleLog);
    if (type == "file")
        this->pool.push_back(new FileLog("../log.txt"));

};
void LogPool::addLevel(Level lvl){
    this->logLevels.at(lvl) = true;
};
void LogPool::printLog(Level lvl, std::string message){
    Message msg = Message(lvl, message);
     for (auto logger : pool)
        logger->output(&msg);
};
bool LogPool::logging(Level lvl){
    return logLevels.at(lvl);
};

LogPool *LogPool::instance = nullptr;

LogPool *LogPool::getInstance(){
    if(!instance)
        instance = new LogPool;
    return instance;
}

void LogPool::clearLoggers(){
    for(auto logger: pool)
        delete logger;
    delete instance;
}