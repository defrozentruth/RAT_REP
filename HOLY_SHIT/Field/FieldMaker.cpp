#include "FieldMaker.h"
#include <iostream>

Field FieldMaker::read(ErrorLog* EL){
    int x, y;
    std::cin >> x >> y;
    if(x <= 0 || y <= 0){
        EL->fieldLog();
//        std::cout << "Invalid field size. The default constructor will be called\n";
        return Field(10, 10);
    }
    else{
        return Field(y, x);
    }
}