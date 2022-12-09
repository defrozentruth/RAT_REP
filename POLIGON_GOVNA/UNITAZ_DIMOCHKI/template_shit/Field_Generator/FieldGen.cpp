#include "FieldGen.hpp"

#include <random>

#include "../Events/Map_Events/sledge.hpp"
#include "../Events/Map_Events/earthquake.hpp"
#include "../Events/Player_Events/enemy.hpp"
#include "../Events/Player_Events/overseer.hpp"
#include "../Events/Player_Events/trap.hpp"
#include "../Events/Player_Events/win.hpp"


void FieldGen::setLevel(Level level){
    this->level = level;
    switch(level){
        case First:
            this->type = new FirstLevel();
            break;
        case Second:
            this->type = new SecondLevel();
            break;
        case Test:
            this->type = new TestLevel();
            break;
    }
}

void FieldGen::setScheme(){
    
    this->scheme = type->generate(this->scheme);
}

void FieldGen::setRandEvent(Field* field, int x, int y){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 5); // define the range
    int r = distr(gen);
    std::uniform_int_distribution<> statsDistr(1, 8); // define the range

    switch (r){
        case 0:
            field->getField()[y][x].changeEvent(new Enemy(field->getPlayer(), statsDistr(gen), statsDistr(gen), statsDistr(gen)));
            field->getField()[y][x].changeEventPresence(true);
            break;
        case 1:
            field->getField()[y][x].changeEvent(new Heal(field->getPlayer(), statsDistr(gen)));
            field->getField()[y][x].changeEventPresence(true);
            break;
        case 2:
            field->getField()[y][x].changeEvent(new Overseer(field->getPlayer(), statsDistr(gen)));
            field->getField()[y][x].changeEventPresence(true);
            break;
        case 3:
            field->getField()[y][x].changeEvent(new Trap(field->getPlayer(), statsDistr(gen)));
            field->getField()[y][x].changeEventPresence(true);
            break;
        case 4:
            field->getField()[y][x].changeEvent(new Win(field->getPlayer()));
            field->getField()[y][x].changeEventPresence(true);
            break;
        case 5:
            field->getField()[y][x].changeEvent(new Sledge(field));
            field->getField()[y][x].changeEventPresence(true);
            break;
        default:
            break;
    }
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
                case CellType::PlayerPos:
                    field->setPlayerX(j);
                    field->setPlayerY(i);
                    field->getField()[i][j].playerVisit();
                    break;
                case CellType::WinM:
                    field->getField()[i][j].changeEvent(new Win(field->getPlayer()));
                    field->getField()[i][j].changeEventPresence(true);
                    break;
                case CellType::EventM:
                    setRandEvent(field, j, i);
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