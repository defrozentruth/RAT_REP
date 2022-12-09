#include "FieldMaker.h"
#include <iostream>

Field* FieldMaker::read(){
    /*int x, y;
    Observer* obs = Observer::get();
    std::cin >> x >> y;
    if(x <= 0 || y <= 0){
        system("cls");
        obs->notify(Message::Level::Error, "Invalid field size. The default constructor will be called\n");
        return Field(10, 10);
    }
    else{
        return Field(y, x);
    }
    */
    Observer* obs = Observer::get();
    int flag;
    std::cout << "Select difficulty level:\n1. Medium\n2. Hard\n";
    std::cin >> flag;
    system("cls");
    switch(flag){
        case 1:{
            MediumLevel firstLevel;
            return firstLevel.create();
        }
        case 2:{
            HardLevel secondLevel;
            return secondLevel.create();
        }
        default:{
            obs->notify(Message::Error, "Non-existent level of difficulty!");
            MediumLevel firstLevel;
            return firstLevel.create();
        }
    }
    return nullptr;
}