#include "errorloggen.hpp"

Message* ErrorLogGenerator::generateMessage(std::string inpLog){
    return new Message(inpLog);
}