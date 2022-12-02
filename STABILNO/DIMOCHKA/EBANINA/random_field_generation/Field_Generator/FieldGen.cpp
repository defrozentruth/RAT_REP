#include "FieldGen.hpp"

#include <random>

#include "../Events/Map_Events/sledge.hpp"
#include "../Events/Map_Events/earthquake.hpp"
#include "../Events/Player_Events/enemy.hpp"
#include "../Events/Player_Events/overseer.hpp"
#include "../Events/Player_Events/trap.hpp"
#include "../Events/Player_Events/win.hpp"


void FieldGen::setType(LevelType* type){
    this->type = type;
}

void FieldGen::setLevel(Level level){
    this->level = level;
    switch(level){
        case First:
            setType(new FirstLevel());
            break;
        case Second:
            setType(new SecondLevel());
            break;
    }
}

void FieldGen::setScheme(){
    
    this->scheme = type->generate(this->scheme);
}

Field* FieldGen::create(){
    this->setScheme();
    int size = scheme.getMask().size();
    Field* field = new Field(size, size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            switch(scheme.getMask()[i][j]){
                case CellType::Block:
                    field->getField()[i][j].changeAccess(false);
                    break;
                case CellType::EnemyM:
                    field->getField()[i][j].changeEvent(new Enemy(field->getPlayer(), 1+(std::rand() % 10), 1+(std::rand() % 10), 1+(std::rand() % 10)));
                    field->getField()[i][j].changeEventPresence(true);
                    break;
                case CellType::OverseerM:
                    field->getField()[i][j].changeEvent(new Overseer(field->getPlayer(), 1+(std::rand() % 10)));
                    field->getField()[i][j].changeEventPresence(true);
                    break;
                case CellType::PlayerPos:
                    field->setPlayerX(j);
                    field->setPlayerY(i);
                    field->getField()[i][j].playerVisit();
                    break;
                case CellType::SledgeM:
                    field->getField()[i][j].changeEvent(new Sledge(field));
                    field->getField()[i][j].changeEventPresence(true);
                    break;
                case CellType::TrapM:
                    field->getField()[i][j].changeEvent(new Trap(field->getPlayer(), 1+(std::rand() % 10)));
                    field->getField()[i][j].changeEventPresence(true);
                    break;
                case CellType::WinM:
                    field->getField()[i][j].changeEvent(new Win(field->getPlayer()));
                    field->getField()[i][j].changeEventPresence(true);
                    break;
                default:
                    break;
            }
        }
    }
    return field;
}

FieldGen::~FieldGen(){
    delete this->type;
}