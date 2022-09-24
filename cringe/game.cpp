#include "game.hpp"

void Game::run(){
    int n, m;
    char common_field;
    std::cout << "Добро пожаловать в игру!" << std::endl;
    std::cout << "Хотите играть на поле стандартного размера? Если да, введите 'y': ";
    std::cin >> common_field;
    if(common_field != 'y'){
        std::cout << "Введите размеры игрового поля: " << std::endl;
        std::cin >> n >> m;
        field = new Field(n,m);
        field->getField()[field->player_x()][field->player_y()].react(); 
    }else{
        field = new Field();
        field->getField()[2][2].setImpassable();
        field->getField()[field->player_x()][field->player_y()].react();
    }
    do{
        system("clear");
        fw.printField(*field);
        mediator.notifyCommandReader();
        mediator.notifyController();
        field->move(mediator.getControllerCommand());
    }while (mediator.getControllerCommand() != QUIT);
    std::cout << "До встречи!" << std::endl;
}