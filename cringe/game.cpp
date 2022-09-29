#include "game.hpp"

void Game::run(){
    int n, m;
    char common_field;
    PowerBuff pb = PowerBuff();
    std::cout << "Добро пожаловать в игру!" << std::endl;
    std::cout << "Хотите играть на поле стандартного размера? Если да, введите 'y': ";
    std::cin >> common_field;
    if(common_field != 'y'){
        std::cout << "Введите размеры игрового поля: " << std::endl;
        std::cin >> n >> m;
        field = new Field(n,m);
        field->getField()[field->player_x()][field->player_y()].react(field->player); 
    }else{
        field = new Field();
        field->getField()[2][2].setImpassable();
        field->getField()[1][1].setEvent(&pb);
        field->getField()[field->player_x()][field->player_y()].react(field->player);
    }
    do{
        system("clear");
        std::cout<<field->player.getPower()<<std::endl;
        fw.printField(*field);
        mediator.notifyCommandReader();
        mediator.notifyController();
        field->move(mediator.getControllerCommand());
    }while (mediator.getControllerCommand() != Player::QUIT);
    std::cout << "До встречи!" << std::endl;
}