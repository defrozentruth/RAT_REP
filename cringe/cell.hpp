#ifndef CELL_HPP
#define CELL_HPP

#include "event.hpp"

class Cell{

public:
    //возможность добавить состояний
    Cell(bool isPassable = true, bool isPushed = false):_is_passable(isPassable),_is_pushed(isPushed){}
    explicit Cell(bool isPassable):_is_passable(isPassable),_is_pushed(false){}
    Cell& operator=(const Cell& cell);

    bool getIsPushed() const;

    bool getIsPassable() const;

    void react();

    void setDefault();

    void setImpassable();

private:
    bool _is_passable;
    bool _is_pushed;
    Event* event;
};

#endif