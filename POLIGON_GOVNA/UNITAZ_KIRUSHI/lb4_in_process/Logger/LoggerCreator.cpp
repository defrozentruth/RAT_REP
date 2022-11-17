#include "LoggerCreator.h"

Logger** LoggerCreator::create(){
    std::cout << "Choose log output format:\n1. Console\n2. File\n3. Console and File\n4. Without logs\n";
    int flag;
    std::cin >> flag;
    switch(flag){
        case 1:{
            Logger **pool = new Logger*[2];
            pool[0] = new ConsoleLogger();
            pool[1] = nullptr;
            return pool;
        }
        case 2:{
            Logger **pool = new Logger*[2];
            pool[0] = new FileLogger();
            pool[1] = nullptr;
            return pool;
        }
        case 3: {
            Logger **pool = new Logger*[2];
            pool[0] = new ConsoleLogger();
            pool[1] = new FileLogger();
            return pool;
        }
        case 4:{
            Logger **pool = nullptr;
            return pool;
        }
    }
    return nullptr;
}