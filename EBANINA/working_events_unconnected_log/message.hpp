#pragma once

#include <iostream>
#include <string>



class Message{
    std::string msg;
public:
    Message(std::string msg): msg(msg) {};
    //~Message();
    friend std::ostream& operator<<(std::ostream& os, const Message* elem);
};