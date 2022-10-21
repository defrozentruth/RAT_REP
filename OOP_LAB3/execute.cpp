#include "execute.hpp"


    void Execute::run(){
        int x,y, player_x, player_y;
        char cmd;
        int hp, armor, agility;
        char choice;
        Field field = Field(false);
        choice = ' ';
        std::cout << "Would you like to use preset for map? y/n\n";
        while(choice != 'y' && choice != 'n'){
            std::cin >> choice;
        };
        if (choice == 'y'){
            field = Field(true);
        }else{
            while(true){
                std::cout << "Enter width, height, starting pos in x y: \n";
                std::cin >> x >> y >> player_x >> player_y;
                if(x <= 0 || y <=0 || player_x < 0 || player_x >= x || player_y <0 || player_y >= y){
                    std::cout << "Wrong data \n";
                }else{
                    field = Field(true, x, y, player_x, player_y);
                    break;
                }
            }
        }
        Controller contr;
        FieldView fview;
        system("clear");
        fview.printField(field);
        std::cout << "Movement is set to WASD" << '\n';
        std::cout << "HP: " << field.getPlayer()->retHP() << " Agility: " << field.getPlayer()->retAgility() << " Attack: " << field.getPlayer()->retAttack() << " Score: "<< field.getPlayer()->retScore() <<'\n';
        std::cin >> cmd;
        while(cmd != 'X' && field.getPlayer()->retWinState() != WIN && field.getPlayer()->retWinState() != LOSE){
            system("clear");
            contr.mover(cmd, field);
            std::cout << '\n';
            
            fview.printField(field);
            std::cout << "Movement is set to WASD" << '\n';
            std::cout << "HP: " << field.getPlayer()->retHP() << " Agility: " << field.getPlayer()->retAgility() << " Attack: " << field.getPlayer()->retAttack() << " Score: "<< field.getPlayer()->retScore()<< '\n';
            if (field.getPlayer()->retOverseer()){
                std::cout << "You have Overseer. Traps marked X, enemies marked T, treasures marked %, Overseer marked O\n";
            }
            if(field.getPlayer()->retWinState() == WIN || field.getPlayer()->retWinState() == LOSE)
                break;
            std::cin >> cmd;
        }
        if(field.getPlayer()->retWinState() == WIN){
            std::cout << "You won!\n";
        }else{
            std::cout << "You lost!\n";
        }
    }

