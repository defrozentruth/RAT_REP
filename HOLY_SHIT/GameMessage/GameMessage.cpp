#include "GameMessage.h"

GameMessage::GameMessage(std::string message): message(message){}

Level GameMessage::get_level(){
    return Level::Game;
}

std::ostream& operator<<(std::ostream& os, const GameMessage* msg){
    os << msg->message << '\n';
    return os;
}