#include "FileLogger.h"
#include "../../Message/GameMessage.h"
#include "../../Message/ErrorMessage.h"
#include "../../Message/InfoMessage.h"

FileLogger::FileLogger(const std::string &name){
    file.open(name, std::ios::out);
}

void FileLogger::print(Message *msg){
    Message::Level msg_lvl = msg->get_level();
    switch(msg_lvl){
        case Message::Level::Game:{
            GameMessage *gmsg = dynamic_cast<GameMessage *>(msg);
            file << gmsg;
            file.flush();
            break;
        }
        case Message::Level::Error:{
            ErrorMessage *emsg = dynamic_cast<ErrorMessage *>(msg);
            file << emsg;
            file.flush();
            break;
        }
        case Message::Level::Info:{
            InfoMessage *imsg = dynamic_cast<InfoMessage *>(msg);
            file << imsg;
            file.flush();
            break;
        }
    }
}

FileLogger::~FileLogger(){
    file.close();
}