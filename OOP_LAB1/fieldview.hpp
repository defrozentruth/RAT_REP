#ifndef FIELDVIEW_HPP
#define FIELDVIEW_HPP

#include <iostream>
#include "field.hpp"
#include "player.hpp"
#include <typeinfo>


class FieldView{
public:
    void printField(Field& field, Player& player);
};

#endif