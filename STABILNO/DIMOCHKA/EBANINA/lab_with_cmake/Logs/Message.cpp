#include "Message.hpp"

std::string Message::getMsg(){
        return this->msg;
    };
std::ostream& operator <<(std::ostream& os, Message& msg){
        if(msg.lvl == Error){
            os << "Error: " << msg.msg;
        }
        if(msg.lvl == Info){
            os << "Info: " << msg.msg;
        }
        if(msg.lvl == Game){
            os << "Game: " << msg.msg;
        }
        return os;
        
    };
    