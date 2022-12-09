#include "SecondLevel.hpp"
#include "../FieldGen.hpp"


FieldScheme& SecondLevel::generate(FieldScheme& scheme){
    scheme.getMask().resize(20);
    for (auto& row : scheme.getMask()){
        row.resize(20);
    }
    return generator.generate(scheme);
}
