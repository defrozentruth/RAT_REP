#include "Message.h"
#include <iostream>
#pragma once

class InfoMessage: public Message{
    std::string message;
public:
    InfoMessage(std::string message);
    Level get_level() override;
    friend std::ostream& operator<<(std::ostream& os, const InfoMessage* msg);
};