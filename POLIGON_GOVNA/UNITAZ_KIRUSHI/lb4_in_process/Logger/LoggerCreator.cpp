#include "LoggerCreator.h"

std::vector<Logger*> LoggerCreator::create(){
    std::cout << "Choose log output format:\n1. Console\n2. File\n3. Console and File\n4. Without logs\n";
    int flag;
    std::vector<Logger*> pool;
    std::cin >> flag;
    switch(flag){
        case 1:{
            pool.push_back(new ConsoleLogger);
            return pool;
        }
        case 2:{
            pool.push_back(new FileLogger);
            return pool;
        }
        case 3: {
            pool.push_back(new ConsoleLogger);
            pool.push_back(new FileLogger);
            return pool;
        }
        case 4:{
            pool.push_back(nullptr);
            return pool;
        }
    }
    pool.push_back(nullptr);
    return pool;
}