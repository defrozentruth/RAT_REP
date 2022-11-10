#include "Message.h"
#include <iostream>
#pragma once

class ErrorMessage: public Message{
    std::string message;
public:
    ErrorMessage(std::string message);
    Level get_level() override;
    friend std::ostream& operator<<(std::ostream& os, const ErrorMessage* msg);
};