#include "InfoLog.h"

void InfoLog::endLog(){
    InfoMessage msg("Game finished!\n");
    pool->printLog(&msg);
}