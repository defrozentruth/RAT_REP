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
        fview.printField(field, player);
        std::cout << "Movement is set to WASD" << '\n';
        std::cout << "HP: " << player.retHP() << " Agility: " << player.retAgility() << " Attack: " << player.retAttack() << " Score: "<< player.retScore() <<'\n';
        std::cin >> cmd;
        while(cmd != 'X' && player.retWinState() != WIN && player.retWinState() != LOSE){
            system("clear");
            contr.mover(cmd, field, player);
            std::cout << '\n';
            
            fview.printField(field, player);
            std::cout << "Movement is set to WASD" << '\n';
            std::cout << "HP: " << player.retHP() << " Agility: " << player.retAgility() << " Attack: " << player.retAttack() << " Score: "<< player.retScore()<< '\n';
            if (player.retOverseer()){
                std::cout << "You have Overseer. Traps marked X, enemies marked T, treasures marked %, Overseer marked O\n";
            }
            if(player.retWinState() == WIN || player.retWinState() == LOSE)
                break;
            std::cin >> cmd;
        }
        if(player.retWinState() == WIN){
            std::cout << "You won!\n";
        }else{
            std::cout << "You lost!\n";
        }
    }

