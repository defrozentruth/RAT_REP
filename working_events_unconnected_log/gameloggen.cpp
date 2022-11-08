#include "gameloggen.hpp"

Message* GameLogGenerator::generateMessage(std::string inpLog){
    std::cout << "trying to create new log\n";
    return new Message(inpLog);
}