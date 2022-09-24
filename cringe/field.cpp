#include "field.hpp"

Field::Field(int height, int width, int x_pos, int y_pos):_height(height),_width(width),x_pos(x_pos),y_pos(y_pos){
    Cell** column = new Cell*[this->_height];
        for(int i = 0; i < this->_height; i++){
            column[i] = new Cell[this->_width];
        }
        this->_game_field = column;
        this->player = Player();
}

Field::Field(const Field& obj):_height(obj._height), _width(obj._width), player(obj.player), x_pos(obj.x_pos), y_pos(obj.y_pos){
    _game_field = new Cell*[_height];
        for(int i = 0; i < _height; i++){
            _game_field[i] = obj._game_field[i];
        }
}

Field& Field::operator=(const Field& obj){
    if(this != &obj){ 
        for(int i = 0; i < _height; i++){
            delete []_game_field[i];
        }

        delete []_game_field;

        _height = obj._height;
        _width = obj._width;
        x_pos = obj.x_pos;
        y_pos = obj.y_pos;
        player = obj.player;
        _game_field = new Cell*[_height];
        for(int i = 0; i < _height; i++){
            _game_field[i] = obj._game_field[i];
        }
    }
    return *this;
}

Field::Field(Field&& obj){
    std::swap(_width, obj._width);
    std::swap(_height, obj._width);
    std::swap(_game_field, obj._game_field);
    std::swap(x_pos, obj.x_pos);
    std::swap(y_pos, obj.y_pos);
    std::swap(player, obj.player);
}

Field& Field::operator=(Field&& obj){
    if(this != &obj){
        std::swap(_width, obj._width);
        std::swap(_height, obj._width);
        std::swap(_game_field, obj._game_field);
        std::swap(x_pos, obj.x_pos);
        std::swap(y_pos, obj.y_pos);
        std::swap(player, obj.player);
    }
    return *this;
}

Field::~Field(){
    for(int i = 0; i < _height; i++){
        delete []_game_field[i];
    }
    delete []_game_field;
}

int Field::height() const{
    return this->_height;
}

int Field::width() const{
    return this->_width;
}

Cell** Field::getField() const{
    return this->_game_field;
}

void Field::setPlayerPosition(int x, int y){
        this->x_pos = x;
        this->y_pos = y;
    }

    int Field::player_x() const{
        return x_pos;
    }

    int Field::player_y() const{
        return y_pos;
    }

    void Field::move(direction dir){
        int x = x_pos;
        int y = y_pos;
        switch(dir){
            case UP:
                x - 1 >= 0 ? x-- : x = _width - 1;
                break;
            case DOWN:
                x = (x + 1) % _width;
                break;
            case LEFT:
                y - 1 >= 0 ? y-- : y = _height - 1;
                break;
            case RIGHT:
                y = (y + 1) % _height;
                break;
            default:
                break;
        }
        if(_game_field[x][y].getIsPassable()){
            _game_field[x_pos][y_pos].setDefault();
            setPlayerPosition(x,y);
            _game_field[x_pos][y_pos].react();
        }else{
            return;
        }
            
    }