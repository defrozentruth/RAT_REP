#include "../Message/Message.h"
#include <iostream>
#pragma once

class GameMessage: public Message{
    std::string message;
public:
    GameMessage(std::string message);
    Level get_level() override;
    friend std::ostream& operator<<(std::ostream& os, const GameMessage* msg);
};