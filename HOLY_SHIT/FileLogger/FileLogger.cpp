#include "FileLogger.h"
#include "../GameMessage/GameMessage.h"
#include "../ErrorMessage/ErrorMessage.h"
#include "../InfoMessage/InfoMessage.h"

FileLogger::FileLogger(const std::string &name){
    file.open(name, std::ios::out);
}

void FileLogger::print(Message *msg){
    Level msg_lvl = msg->get_level();
    switch(msg_lvl){
        case Level::Game:{
            GameMessage *gmsg = dynamic_cast<GameMessage *>(msg);
            file << gmsg;
            file.flush();
            break;
        }
        case Level::Error:{
            ErrorMessage *emsg = dynamic_cast<ErrorMessage *>(msg);
            file << emsg;
            file.flush();
            break;
        }
        case Level::Info:{
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