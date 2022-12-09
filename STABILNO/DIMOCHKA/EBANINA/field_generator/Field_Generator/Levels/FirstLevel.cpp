#include "FirstLevel.hpp"
#include "../FieldGen.hpp"
#define FSize 5

FieldScheme& FirstLevel::generate(FieldScheme& scheme){
    scheme.getMask().resize(FSize);
    for (auto& row : scheme.getMask()){
        row.resize(FSize);
    }
    scheme.getFreeCells().resize(FSize*FSize);
    int counter = 0;
    for (int i = 0; i < FSize; i++){
        for (int j = 0; j < FSize; j++){
            scheme.getFreeCells()[counter].first = i;
            scheme.getFreeCells()[counter].second = j;
            counter++;
        }
    }

    return generator.generate(scheme);
}
