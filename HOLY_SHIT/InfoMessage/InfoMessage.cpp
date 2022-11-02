#include "InfoMessage.h"

InfoMessage::InfoMessage(std::string message): message(message){}

Level InfoMessage::get_level(){
    return Level::Game;
}

std::ostream& operator<<(std::ostream& os, const InfoMessage* msg){
    os << msg->message << '\n';
    return os;
}