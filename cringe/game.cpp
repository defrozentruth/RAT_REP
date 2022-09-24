#include "game.hpp"

Game::Game(){
    fw = new FieldView();
    cr = new CommandReader();
    control = new Controller();
    mediator = new Mediator(*cr, *control);
}

Game::~Game(){
    delete fw;
    delete cr;
    delete control;
    delete mediator;
}

void Game::run(){
    int n, m;
    char common_field;
    std::cout << "Добро пожаловать в игру!" << std::endl;
    std::cout << "Хотите играть на поле стандартного размера? Если да, введите 'y': ";
    std::cin >> common_field;
    if(common_field != 'y'){
        std::cout << "Введите размеры игрового поля: " << std::endl;
        std::cin >> n >> m;
        Field* field = new Field(n,m, 0, 0);
        field->getField()[field->player_x()][field->player_y()].react(); 
    }else{
        Field* field = new Field(3, 3, 0, 0);
        // field->getField()[2][2].setImpassable();
        field->getField()[field->player_x()][field->player_y()].react();
    }
    do{
        system("clear");
        fw->printField(*field);
        mediator->notifyCommandReader();
        mediator->notifyController();
        field->move(mediator->getControllerCommand());
    }while (mediator->getControllerCommand() != QUIT);
    std::cout << "До встречи!" << std::endl;
}