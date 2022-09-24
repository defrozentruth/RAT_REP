#ifndef GAME_HPP
#define GAME_HPP

#include "field.hpp"
#include "field_view.hpp"
#include "command.hpp"
#include "controller.hpp"
#include "mediator.hpp"
#include "direction.hpp"
#include <iostream>


class Game{

public:
    void run();
private:
    FieldView fw;
    Mediator mediator;
    Field* field;
};

#endif