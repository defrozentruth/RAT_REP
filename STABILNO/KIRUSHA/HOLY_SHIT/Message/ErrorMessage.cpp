#include "ErrorMessage.h"

ErrorMessage::ErrorMessage(std::string message): message(message){}

Message::Level ErrorMessage::get_level(){
    return Level::Error;
}

std::ostream& operator<<(std::ostream& os, const ErrorMessage* msg){
    os << msg->message << '\n';
    return os;
}