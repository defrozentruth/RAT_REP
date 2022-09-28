#include "execute.hpp"


    void Execute::run(){
        int x,y, player_x, player_y;
        char cmd;
        int hp, armor, agility;
        char choice;
        Player player;
        std::cout << "Would you like to use preset for player? y/n\n";
        while(choice != 'y' && choice != 'n'){
            std::cin >> choice;
        };
        if (choice == 'y'){
            player =  Player();
        }else{
            std::cout << "Enter hp, armor, agility: \n";
            std::cin >> hp >> armor >> agility;
            player =  Player(hp, armor, agility);
        };
        Field field;
        choice = ' ';
        std::cout << "Would you like to use preset for map? y/n\n";
        while(choice != 'y' && choice != 'n'){
            std::cin >> choice;
        };
        if (choice == 'y'){
            field = Field();
        }else{
            while(true){
                std::cout << "Enter width, height, starting pos in x y: \n";
                std::cin >> x >> y >> player_x >> player_y;
                if(x <= 0 || y <=0 || player_x < 0 || player_x >= x || player_y <0 || player_y >= y){
                    std::cout << "Wrong data \n";
                }else{
                    field = Field(x, y, player_x, player_y);
                    break;
                }
            }
        }
        Controller contr;
        FieldView fview;
        system("clear");
        fview.printField(field);
        std::cin >> cmd;
        while(cmd != 'X'){
            contr.mover(cmd, field);
            std::cout << '\n';
            system("clear");
            fview.printField(field);
            std::cin >> cmd;
        }
    }

