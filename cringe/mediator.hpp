#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "controller.hpp"
#include "command.hpp"

class Mediator{

public:
    Mediator(CommandReader& cr, Controller& control):cr(cr), control(control){}
    void notifyCommandReader();

    void notifyController();

    direction getControllerCommand();

private:
    CommandReader cr;
    Controller control;
};

#endif