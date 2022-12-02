#include "FirstLevel.hpp"
#include "../FieldGen.hpp"


FieldScheme& FirstLevel::generate(FieldScheme& scheme){
    scheme.getMask().resize(5);
    for (auto& row : scheme.getMask()){
        row.resize(5);
    }
    return generator.generate(scheme);
}
