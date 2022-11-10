#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "controller.hpp"
#include "command.hpp"

class Mediator{

public:
    Mediator(){}
    void notifyCommandReader();

    // void notifyController();

    Player::command getControllerCommand();

private:
    CommandReader cr;
    Controller control;
};

#endif