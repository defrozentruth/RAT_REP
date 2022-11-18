#include <iostream>
#pragma once

class Message{
public:
    enum Level{
        Game,
        Info,
        Error
    };
    Message(Level lvl, std::string message): lvl(lvl),message(message){};
    std::string to_str();
    friend std::ostream& operator<<(std::ostream& os, Message* msg);
private:
    std::string message;
    Level lvl;
};