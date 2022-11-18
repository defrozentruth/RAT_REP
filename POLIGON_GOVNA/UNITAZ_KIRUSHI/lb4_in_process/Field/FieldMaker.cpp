#include "FieldMaker.h"
#include <iostream>

Field FieldMaker::read(){
    int x, y;
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
}