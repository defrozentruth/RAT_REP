#include "SecondLevel.hpp"
#include "../FieldGen.hpp"

#define SSize 20

FieldScheme& SecondLevel::generate(FieldScheme& scheme){
    scheme.getMask().resize(SSize);
    for (auto& row : scheme.getMask()){
        row.resize(20);
    }
    scheme.getFreeCells().resize(SSize*SSize);
    int counter = 0;
    for (int i = 0; i < SSize; i++){
        for (int j = 0; j < SSize; j++){
            scheme.getFreeCells()[counter].first = i;
            scheme.getFreeCells()[counter].second = j;
            counter++;
        }
    }
    return generator.generate(scheme);
}
