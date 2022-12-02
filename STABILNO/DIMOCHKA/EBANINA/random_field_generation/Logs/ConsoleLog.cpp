#include "ConsoleLog.hpp"

void ConsoleLog::output(Message* msg){
        std::cout << *msg << '\n';
    };