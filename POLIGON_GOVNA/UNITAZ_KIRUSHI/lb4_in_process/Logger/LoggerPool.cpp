#include "LoggerPool.h"
#include "iostream"

void LoggerPool::setPool(std::vector<Logger*> logarr){
    this->logarr = logarr;
}

void LoggerPool::printLog(Message *msg){
    if(logarr.at(0) != nullptr){
        for(int i = 0; i<logarr.size(); i++){
            logarr[i]->print(msg);
        }
    }
}

LoggerPool::~LoggerPool(){
    for(int i = 0; i<logarr.size(); i++){
        delete(logarr.at(i));
    }
}