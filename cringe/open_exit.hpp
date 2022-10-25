#ifndef OPEN_EXIT_HPP
#define OPEN_EXIT_HPP

#include "Ifield_event.hpp"
#include "win.hpp"

class Exit: public Ifield_event{
    void goToEmptyCell(int old_x, int old_y);
public:    
    Exit(Field* field): field(field){};
    void change_state() override;
    Exit* clone() override;
protected:
    Field* field;
};


#endif