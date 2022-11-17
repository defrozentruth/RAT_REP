#include <iostream>
#include "../Field/Field.h"
#include "../Controller/Controller.h"
#include "../Field/FieldView.h"
#include "Runner.h"
#include "../Field/FieldMaker.h"
#include "../LogType/GameLog.h"
#include "../LogType/InfoLog.h"
#include "../LogType/ErrorLog.h"
#include "../Logger/LoggerPool.h"
#include "../Logger/LoggerCreator.h"
#include <stdlib.h>
#include <windows.h>

int Runner::start(){
    char command;
    FieldMaker reader;
    LoggerCreator crt;
    LoggerPool pool = LoggerPool();
    pool.setPool(crt.create());
    GameLog GL(&pool);
    InfoLog IL(&pool);
    ErrorLog EL(&pool);
    std::cout << "Set the size of the field\n";
    Field field = reader.read(&EL);
    Controller cont;
    FieldView printer;
    printer.printField(field);
    std::cout << "Movement is set to WASD\n";
    std::cin >> command;
    system("cls");
    while(command != 'X'){
        cont.process(command, field, &GL, &EL);
        if(field.getFlag() < 0 || field.getFlag()>0){
            break;
        }
        printer.printField(field);
        field.getPlayer().seeParameters();
        std::cin >> command;
        system("cls");
    }
    EL.endLog();
    return 0;
}