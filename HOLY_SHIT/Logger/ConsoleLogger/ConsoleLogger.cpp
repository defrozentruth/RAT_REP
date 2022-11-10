#include "ConsoleLogger.h"
#include "../../Message/GameMessage.h"
#include "../../Message/ErrorMessage.h"
#include "../../Message/InfoMessage.h"

void ConsoleLogger::print(Message* msg){
    Message::Level msg_lvl = msg->get_level();
    switch(msg_lvl){
        case Message::Level::Game:{
            GameMessage *gmsg = dynamic_cast<GameMessage *>(msg);
            std::cout << gmsg;
            break;
        }
        case Message::Level::Error:{
            ErrorMessage *emsg = dynamic_cast<ErrorMessage *>(msg);
            std::cout << emsg;
            break;
        }
        case Message::Level::Info:{
            InfoMessage *imsg = dynamic_cast<InfoMessage *>(msg);
            std::cout << imsg;
            break;
        }
    }
}