#include "Observer.h"

Observer::Observer(){
    std::string str;
    std::cout << "Do you want to set logging levels? [y/n]\n";
    std::cin >> str;
    if(str == "y") {
        std::cout << "Do you want Error logs? [y/n]\n";
        std::cin >> str;
        if (str == "y") { logLevels.at(Message::Level::Error) = true; }
        std::cout << "Do you want Info logs? [y/n]\n";
        std::cin >> str;
        if (str == "y") { logLevels.at(Message::Level::Info) = true; }
        std::cout << "Do you want Game logs? [y/n]\n";
        std::cin >> str;
        if (str == "y") { logLevels.at(Message::Level::Game) = true; }
    }
}

void Observer::setLoggers(LoggerPool *pool){
    this->pool = pool;
}

void Observer::notify(Message::Level lvl, std::string msg){
    if(logLevels.at(lvl)){
        Message message(lvl, msg);
        pool->printLog(&message);
    }
}

Observer *Observer::obs = nullptr;

Observer *Observer::get(){
    if(!obs)
        obs = new Observer;
    return obs;
}