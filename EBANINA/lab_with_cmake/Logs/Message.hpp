#include <string>
#include <iostream>
#pragma once



enum Level{
    Error,
    Game,
    Info
};


class Message{
    std::string msg;
    Level lvl;
public:
    Message(Level lvl, std::string msg): lvl(lvl), msg(msg){};
    std::string getMsg();
    friend std::ostream& operator <<(std::ostream& os, Message& msg);
};