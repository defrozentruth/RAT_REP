// #include "game.hpp"
#include "field.hpp"
#include "field_view.hpp"
#include "command.hpp"
#include "controller.hpp"
#include "mediator.hpp"
#include "direction.hpp"
#include <iostream>

int main(){

    FieldView fw = FieldView();
    CommandReader* cr = new CommandReader();
    Controller* control = new Controller();
    Mediator medi = Mediator(*cr, *control);
    int n, m;
    std::cin >> n >> m;
    Field* field = new Field(n,m);
    field->setPlayerPosition(0,0);
    field->getField()[field->player_x()][field->player_y()].react();
    do{
        system("clear");
        fw.printField(*field);
        medi.notifyCommandReader();
        medi.notifyController();
        field->move(medi.getControllerCommand());
    }while (medi.getControllerCommand() != QUIT);
    
    return 0;

}