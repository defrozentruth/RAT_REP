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

            field.getField()[0][1].changeAccess(false);
            field.getField()[1][7].changeAccess(false);
            field.getField()[2][1].changeAccess(false);
            field.getField()[2][2].changeAccess(false);
            field.getField()[2][3].changeAccess(false);
            field.getField()[4][5].changeAccess(false);
            field.getField()[6][7].changeAccess(false);
            field.getField()[8][9].changeAccess(false);
            field.getField()[9][8].changeAccess(false);

            Trap testTrap = Trap(field.getPlayer());
            field.getField()[1][1].changeEvent(&testTrap);
            field.getField()[1][1].changeEventPresence(true);

            Enemy testEnemy = Enemy(field.getPlayer());
            field.getField()[1][2].changeEvent(&testEnemy);
            field.getField()[1][2].changeEventPresence(true);

            Overseer testOV = Overseer(field.getPlayer());
            field.getField()[1][3].changeEvent(&testOV);
            field.getField()[1][3].changeEventPresence(true);

            Win testWin = Win(field.getPlayer());
            field.getField()[1][4].changeEvent(&testWin);
            field.getField()[1][4].changeEventPresence(true);

            testEnemy = Enemy(field.getPlayer(), 10, 10, 10);
            field.getField()[1][5].changeEvent(&testEnemy);
            field.getField()[1][5].changeEventPresence(true);

            // testEnemy = Enemy(field.getPlayer(), 5, 7, 6);
            // field.getField()[2][4].changeEvent(&testEnemy);
            // field.getField()[2][4].changeEventPresence(true);

            testEnemy = Enemy(field.getPlayer(), 4, 3, 3);
            field.getField()[2][5].changeEvent(&testEnemy);
            field.getField()[2][5].changeEventPresence(true);

            // testEnemy = Enemy(field.getPlayer(), 1, 15, 7);
            // field.getField()[2][6].changeEvent(&testEnemy);
            // field.getField()[2][6].changeEventPresence(true);

            // testOV = Overseer(field.getPlayer(), 1);
            // field.getField()[2][7].changeEvent(&testOV);
            // field.getField()[2][7].changeEventPresence(true);

            Earthquake testEQ = Earthquake(&field);
            field.getField()[7][2].changeEvent(&testEQ);
            field.getField()[7][2].changeEventPresence(true);

            Sledge testSledge = Sledge(&field);
            field.getField()[9][4].changeEvent(&testSledge);
            field.getField()[9][4].changeEventPresence(true);

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
                std::cout << "You have Overseer. Traps marked X, enemies marked T, treasures marked %, Overseer marked O, sledge marked P\n";
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

