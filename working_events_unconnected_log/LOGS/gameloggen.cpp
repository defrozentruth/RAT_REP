#include "gameloggen.hpp"

Message* GameLogGenerator::generateMessage(std::string inpLog){
    return new Message(inpLog);
}