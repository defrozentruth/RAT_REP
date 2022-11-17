#include "ErrorLog.h"

void ErrorLog::fieldLog(){
    ErrorMessage msg = ErrorMessage("Invalid field size. The default constructor will be called\n");
    pool->printLog(&msg);
}

void ErrorLog::impassableLog(){
    ErrorMessage msg = ErrorMessage("This cell isn't passable!");
    pool->printLog(&msg);
}

void ErrorLog::endLog(){
    ErrorMessage msg("Game finished!\n");
    pool->printLog(&msg);
}