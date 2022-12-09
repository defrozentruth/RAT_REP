#include "TestLevel.hpp"
#include "../FieldGen.hpp"


FieldScheme& TestLevel::generate(FieldScheme& scheme){
    scheme.getMask().resize(20);
    for (auto& row : scheme.getMask()){
        row.resize(20);
    }
    return generator.generate(scheme);
}
