#include "SecondLevel.hpp"
#include "../FieldGen.hpp"


FieldScheme& SecondLevel::generate(FieldScheme& scheme){
    scheme.getMask().resize(10);
    for (auto& row : scheme.getMask()){
        row.resize(10);
    }
    return generator.generate(scheme);
}
