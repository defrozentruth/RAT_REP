#include <string>
#include <iostream>
#pragma once



enum LogLevel{
    Error,
    Game,
    Info
};


class Message{
    std::string msg;
    LogLevel lvl;
public:
    Message(LogLevel lvl, std::string msg): lvl(lvl), msg(msg){};
    std::string getMsg();
    friend std::ostream& operator <<(std::ostream& os, Message& msg);
};