#include "game.hpp"
#include <stdlib.h>

void Game::run(){
    this->notify(LogType::INFO, "Game started");
    int n, m;
    char common_field;

    std::cout << "Добро пожаловать в игру!" << std::endl;
    std::cout << "Хотите играть на поле стандартного размера? Если да, введите 'y': ";
    std::cin >> common_field;
    if(common_field != 'y'){
        
        std::cout << "Введите размеры игрового поля: " << std::endl;
        
        std::cin >> n >> m;
        
        if(n >= 3 && m >= 3){
            field = new Field(n,m);
            std::string log_txt = "Built field with size:" +  std::to_string(n) + 'x' + std::to_string(m);
            this->notify(LogType::INFO, log_txt);
        }else{
            std::cout<<"Incorrect size. Build default size (10x10)\n";
            field = new Field(10,10);
            this->notify(LogType::ERROR, "Incorrect size. Build default size (10x10)");
        }
        
        field->react();
        
    
    }else{
        field = new Field();
        
        EventAbstractFactory* factory = new EnemyFactory(field->getPlayer(), field);
        Event* enemy = factory->createEvent();
        
        factory = new ExitFactory(field);
        Event* e_exit = factory->createEvent();

        factory = new PowerBuffFactory(field->getPlayer());
        Event* pb = factory->createEvent();

        field->getField()[2][2].setImpassable();
        field->getField()[1][0].setImpassable();
        field->getField()[1][1].setEvent(e_exit);
        field->getField()[1][2].setEvent(pb);
        field->getField()[1][3].setEvent(enemy);
        field->react();
        this->notify(LogType::INFO, "Built default field");
    }

    do{
        system("clear");
        fw.printField(*field);
        
        std::cout<<"|power=" << field->getPlayer()->getPower()<< "|HP=" << field->getPlayer()->getHP() <<"|points=" << field->getPlayer()->getPoints() << '|' << std::endl;
        mediator.notifyCommandReader();
        field->move(mediator.getControllerCommand());
        
        if(field->getState() == Field::WIN){
            this->notify(LogType::GAME, "Player win!");
            break;
        }

        if(field->getState() == Field::LOSE){
            this->notify(LogType::GAME, "Player lose!");
            break;
        }
        // mediator.notifyController();
        
    }while (mediator.getControllerCommand() != Player::QUIT);
    std::cout << "До встречи!" << std::endl;
    this->notify(LogType::INFO, "Game finished");
}