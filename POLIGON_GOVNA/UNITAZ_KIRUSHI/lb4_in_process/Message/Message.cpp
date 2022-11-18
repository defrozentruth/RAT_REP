#include "../Message/Message.h"

std::string Message::to_str(){
    std::string res;
    switch(lvl){
        case Level::Game:
            res = res + "Game: " + message;
            return res;
        case Level::Info:
            res = res + "Info: " + message;
            return res;
        case Level::Error:
            res = res + "Error: " + message;
            return res;
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, Message* msg){
    os << msg->to_str() << "\n";
    return os;
}