#include <iostream>
#include "../Field/Field.h"
#include "../Runner/Mediator.h"
#include "Runner.h"
#include "../Field/FieldMaker.h"
#include "../Logger/LoggerCreator.h"

int Runner::start(){
    char command;
    FieldMaker reader;
    LoggerCreator crt;
    LoggerPool pool = LoggerPool();
    pool.setPool(crt.create());
    Observer* obs = Observer::get();
    obs->setLoggers(&pool);
    std::cout << "Set the size of the field\n";
    Field field = reader.read();
    Control* ctrl = new Control;
    CommandReader creader;
    FieldView printer;
    Mediator mediator(ctrl, &creader);
    obs->notify(Message::Level::Info, "Game started!\n");
    printer.printField(field);
    std::cout << "Movement is set to WASD\n";
    mediator.execute(field,printer);
    obs->notify(Message::Level::Info, "Game finished!\n");
    return 0;
}