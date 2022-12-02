#include <iostream>
#include "../Cell/Cell.h"
#include "Field.h"

Field::Field(int y, int x):y(y), x(x){
    field = new Cell*[y];
    for(int i = 0; i<y; i++){
        field[i] = new Cell[x];
    }
}
Field::Field(const Field& field):
        y(field.y),
        x(field.x),
        player(field.player),
        ply(field.ply),
        plx(field.plx){
    this->field = new Cell* [this->y];
    for (int i = 0; i < this->y; i++) {
        this->field[i] = new Cell[this->x];
        for (int j = 0; j < this->x; j++) {
            this->field[i][j] = field.field[i][j];
        }
    }
};
void Field::swap(Field& map){
    std::swap(y, map.y);
    std::swap(x, map.x);
    std::swap(player, map.player);
    std::swap(ply, map.ply);
    std::swap(plx, map.plx);
    for (int i = 0; i < this->y; i++) {
        for (int j = 0; j < this->x; j++) {
            std::swap(field[i][j], map.field[i][j]);
        }
    }
}
Field& Field::operator =(const Field& field){
    if(this != &field){
        Field(field).swap(*this);
    }
    return *this;
}
Field::Field(Field&& field){
this->swap(field);
}
Field& Field::operator =(Field&& field){
    if (this != &field)
        this->swap(field);
    return *this;
}
Cell** Field::getField(){
    return field;
}
Player& Field::getPlayer(){
    return this->player;
}
void Field::setPlx(int x){
    this->plx = x;
}
void Field::setPly(int y){
    this->ply = y;
}
int Field::getHeight(){
    return y;
}
int Field::getWidth(){
    return x;
}
void Field::setFlag(int flag){
    this->flag = flag;
}
int Field::getFlag(){
    return flag;
}
void Field::move(int dx, int dy){
    Observer* obs = Observer::get();
    int tempy = ply+dy;
    int tempx = plx+dx;
    if(tempy >= y){
        tempy = 0;
    }
    else if(tempy < 0){
        tempy = y-1;
    }
    if(tempx >= x){
        tempx = 0;
    }
    else if(tempx < 0){
        tempx = x-1;
    }
    if(field[tempy][tempx].getType() != Cell::IMPASSABLE){
        field[ply][plx].setType(Cell::PASSABLE);
        this->ply = tempy;
        this->plx = tempx;
        field[ply][plx].setType(Cell::ACTIVE);
        obs->notify(Message::Level::Game, "Player's position changed. New position: [" + std::to_string(plx) + "," + std::to_string(ply) + "]\n");
        if(field[ply][plx].getEvent() != nullptr){
            field[ply][plx].getEvent()->processEvent(this);
            field[ply][plx].changeEvent(nullptr);
            field[ply][plx].setType(Cell::ACTIVE);
        }
    }
    else{
        obs->notify(Message::Level::Error, "This cell isn't passable!\n");
    }
}