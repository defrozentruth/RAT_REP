#include "infologgen.hpp"

Message* InfoLogGenerator::generateMessage(std::string inpLog){
    return new Message(inpLog);
}