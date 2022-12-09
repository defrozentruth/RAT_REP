#include "TestLevel.hpp"
#include "../FieldGen.hpp"

#define TSize 20


FieldScheme& TestLevel::generate(FieldScheme& scheme){
    scheme.getMask().resize(TSize);
    for (auto& row : scheme.getMask()){
        row.resize(TSize);
    }
    scheme.getFreeCells().resize(TSize*TSize);
    int counter = 0;
    for (int i = 0; i < TSize; i++){
        for (int j = 0; j < TSize; j++){
            scheme.getFreeCells()[counter].first = i;
            scheme.getFreeCells()[counter].second = j;
            counter++;
        }
    }
    return generator.generate(scheme);
}
