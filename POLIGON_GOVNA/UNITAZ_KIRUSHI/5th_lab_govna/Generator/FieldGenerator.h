#pragma once
#include "ArmorRule.h"
#include "EnemyRule.h"
#include "HealRule.h"
#include "PlateRule.h"
#include "PlayerRule.h"
#include "WallRule.h"
#include "../Field/Field.h"

template<typename ... Rules>
class FieldGenerator{
public:
    Field *generate(int field_height, int field_width);
    FieldGenerator() = default;
private:
    template<typename Rule>
    void applyRule(Field *field);
};

template<typename... Rules>
Field *FieldGenerator<Rules...>::generate(int height, int width) {
    auto *field = new Field(height, width);
    (applyRule<Rules>(field), ...);
    return field;
}

template<typename... Rules>
template<typename Rule>
void FieldGenerator<Rules...>::applyRule(Field *field) {
    Rule rule;
    rule.place(field);
}