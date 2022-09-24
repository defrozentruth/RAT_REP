#include <iostream>
#include <vector>

class Cell;
class Player;

class Event{

public:
    virtual ~Event() = 0;
    virtual void change_statement(Cell& currentCell) = 0;
};

class Cell{

private:
    bool _is_passable;
    bool _is_pushed;
    Event* event;
public:
    Cell(bool isPassable = true, bool isPushed = false):_is_passable(isPassable),_is_pushed(isPushed){}
    explicit Cell(bool isPassable):_is_passable(isPassable),_is_pushed(false){}
    Cell& operator=(const Cell& cell){
        if(this != &cell){
            _is_passable = cell._is_passable;
            _is_pushed = cell._is_pushed;
            event = cell.event;
        }
        return *this;
    }
    bool getIsPushed(){
        return this->_is_pushed;
    }
    bool getIsPassable(){
        return this->_is_passable;
    }
    void react(){
        this->_is_pushed = true;
    }
    void setDefault(){
        this->_is_pushed = false;
    }
    void setImpassable(){
        _is_passable = false;
    }
};

enum direction{
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3, 
        QUIT = 4
    };

class Player{

private:
    int _hitPoints;
    int _mana;
    int _power;
public:

    Player(int HP = 100, int mana = 100, int power = 1):_hitPoints(HP), _mana(mana), _power(power){}
    Player(const Player& obj):_hitPoints(obj._hitPoints), _mana(obj._mana), _power(obj._power){}
    Player& operator=(const Player& obj){
        if(this != &obj){
            _hitPoints = obj._hitPoints;
            _mana = obj._mana;
            _power = obj._power;
        }
        return *this;
    }
};

class Field{

private:
    int _height;
    int _width;
    int x_pos;
    int y_pos;
    Cell** _game_field;
public:
    Player player;

    Field(int height = 3, int width = 3):_height(height), _width(width){
        Cell** column = new Cell*[this->_height];
        for(int i = 0; i < this->_height; i++){
            column[i] = new Cell[this->_width];
        }
        this->_game_field = column;
        this->player = Player();
    }
    Field(const Field& obj):_height(obj._height), _width(obj._width), player(obj.player){
        _game_field = new Cell*[_height];
        for(int i = 0; i < _height; i++){
            _game_field[i] = obj._game_field[i];
        }
    }
    Field& operator=(const Field& obj){
        if(this != &obj){
            
            for(int i = 0; i < _height; i++){
                delete []_game_field[i];
            }
            delete []_game_field;

            _height = obj._height;
            _width = obj._width;
            player = obj.player;
            _game_field = new Cell*[_height];
            for(int i = 0; i < _height; i++){
                _game_field[i] = obj._game_field[i];
            }
        }
        return *this;
    }
    int height() const{
        return _height;
    }
    
    int width() const{
        return _width;
    }
    
    Cell** getField() const{
        return _game_field;
    }

    void setPlayerPosition(int x, int y){
        this->x_pos = x;
        this->y_pos = y;
    }
    int player_x() const{
        return x_pos;
    }
    int player_y() const{
        return y_pos;
    }
    void move(direction dir){
        switch(dir){
            case UP:
                x_pos--;
                break;
            case DOWN:
                x_pos++;
                break;
            case LEFT:
                y_pos--;
                break;
            case RIGHT:
                y_pos++;
                break;
            default:
                break;
        }
        setPlayerPosition(x_pos, y_pos);
    }
};

class CellView{
public:
    void printCell(Cell& cell){
        if(cell.getIsPassable()){
            if(cell.getIsPushed()){
                std::cout<<"[*]";
            }else{
                std::cout<<"[ ]";
            }
        }else{
            std::cout<<"[#]";
        }
    }
};

class FieldView{
private:
    CellView cw;
public:
    void printField(Field& field){
        for(int i = 0; i < field.height(); i++){
            for(int j = 0; j < field.width(); j++){
                cw.printCell(field.getField()[i][j]);
            }
            std::cout<<'\n';
        }
    }
};

class CommandReader{
private:
    char command;
public:
    void setCommand(){
        std::cin >> this->command;
    }

    char getCommand(){
        return this->command;
    }
};

class Controller{
    
public:
    direction command;
    void getCommand(char command){
        switch (command)
        {
        case 'w':
            this->command = UP; 
            break;
        case 'a':
            this->command = LEFT;
            break;
        case 's':
            this->command = DOWN;
            break;
        case 'd':
            this->command = RIGHT;
            break;
        case 'q':
            this->command = QUIT;
            break;
        default:
            break;
        }
    }
};

class Mediator{
    CommandReader cr;
    Controller control;
public:
    Mediator(CommandReader cr, Controller control):cr(cr), control(control){}
    void notifyCommandReader(){
        cr.setCommand();
    }
    void notifyController(){
        control.getCommand(cr.getCommand());
    }
    direction getControllerCommand(){
        return control.command;
    }
};


int main(){
    
    FieldView fw = FieldView();
    CommandReader* cr = new CommandReader();
    Controller* control = new Controller();
    Mediator medi = Mediator(*cr, *control);
    int n = 15, m = 5;
    Field* field = new Field(n,m);
    field->setPlayerPosition(0,0);
    field->getField()[field->player_x()][field->player_y()].react();
    do{
        system("clear");
        fw.printField(*field);
        medi.notifyCommandReader();
        medi.notifyController();
        field->getField()[field->player_x()%n][field->player_y()%m].setDefault();
        field->move(medi.getControllerCommand());
        field->getField()[field->player_x()%n][field->player_y()%m].react();
    }while (medi.getControllerCommand() != QUIT);
    
    return 0;
}
