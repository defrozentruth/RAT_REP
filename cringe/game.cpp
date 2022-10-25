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
        
        if(n >= 3 && m >= 3){
            field = new Field(n,m);
        }else{
            std::cout<<"Incorrect size. Build default size (10x10)\n";
            field = new Field(10,10);
        }
        
        field->react(); 
    
    }else{
        field = new Field();
            
        PowerBuff pb = PowerBuff(field->getPlayer());
        Enemy enemy = Enemy(field->getPlayer(), field);
        Exit exit = Exit(field);

        field->getField()[2][2].setImpassable();
        field->getField()[1][0].setImpassable();
        field->getField()[1][1].setEvent(&exit);
        field->getField()[1][2].setEvent(&pb);
        field->getField()[1][3].setEvent(&enemy);
        field->react();
    }

    do{
        system("clear");
        fw.printField(*field);
        
        std::cout<<"|power=" << field->getPlayer()->getPower()<< "|HP=" << field->getPlayer()->getHP() <<"|points=" << field->getPlayer()->getPoints() << '|' << std::endl;
        mediator.notifyCommandReader();
        field->move(mediator.getControllerCommand());
        
        if(field->getState() == Field::WIN){
            std::cout<<"You win!!!\n";
            break;
        }

        if(field->getState() == Field::LOSE){
            std::cout<<"You lose!!!\n";
            break;
        }
        // mediator.notifyController();
        
    }while (mediator.getControllerCommand() != Player::QUIT);
    std::cout << "До встречи!" << std::endl;
}