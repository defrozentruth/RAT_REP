#include <iostream>
#include "../Field/Field.h"
#include "../Controller/Controller.h"
#include "../FieldView/FieldView.h"
#include "Runner.h"
#include "../FieldMaker/FieldMaker.h"
#include "../GameLog/GameLog.h"
#include "../InfoLog/InfoLog.h"
#include "../ErrorLog/ErrorLog.h"
#include "../LoggerPool/LoggerPool.h"
#include "../LoggerCreator/LoggerCreator.h"
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