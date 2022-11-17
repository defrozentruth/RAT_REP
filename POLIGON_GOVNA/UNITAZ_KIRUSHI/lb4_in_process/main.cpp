#include "Runner/Runner.h"
#include <cstdlib>

int main(){
    Runner run;
    run.start();
    system("pause");
    return 0;
}

/*
 Убрать dynamic_cast в логгерах
 Доделать деструктор FileLogger
 поместить enum в Message
 вектор в LoggerPool
 */