#pragma once
#include <iostream>
#include "cell.hpp"
#include "field.hpp"
#include "event.hpp"


class FieldView{
public:
    void printField(Field& field);
};