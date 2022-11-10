#include "LoggerPool.h"
#include "iostream"

void LoggerPool::setPool(Logger **logarr){
    this->logarr = logarr;
}

void LoggerPool::printLog(Message *msg){
    if(logarr){
        if(logarr[2]) {
            for (int i = 0; i < 2; i++) {
                if (logarr[i]) {
                    logarr[i]->print(msg);
                }
            }
        }
        else{
            if (logarr[0]) {
                logarr[0]->print(msg);
            }
        }
    }
}

LoggerPool::~LoggerPool(){
    delete(logarr);
}