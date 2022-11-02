#include "ConsoleLogger.h"
#include "../GameMessage/GameMessage.h"
#include "../ErrorMessage/ErrorMessage.h"
#include "../InfoMessage/InfoMessage.h"

void ConsoleLogger::print(Message* msg){
    Level msg_lvl = msg->get_level();
    switch(msg_lvl){
        case Level::Game:{
            GameMessage *gmsg = dynamic_cast<GameMessage *>(msg);
            std::cout << gmsg;
            break;
        }
        case Level::Error:{
            ErrorMessage *emsg = dynamic_cast<ErrorMessage *>(msg);
            std::cout << emsg;
            break;
        }
        case Level::Info:{
            InfoMessage *imsg = dynamic_cast<InfoMessage *>(msg);
            std::cout << imsg;
            break;
        }
    }
}