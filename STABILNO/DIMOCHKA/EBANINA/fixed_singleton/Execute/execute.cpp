#include "execute.hpp"


    void Execute::run(){
        LogPool* logger = LogPool::getInstance();
        int x,y, player_x, player_y;
        char cmd;
        int hp, armor, agility;
        char choice;
        choice = ' ';
        std::cout << "Would you like to log? y/n\n";
        while(choice != 'y' && choice != 'n'){
            std::cin >> choice;
        };
        if(choice == 'y'){
            std::cout << "Where do you want to log?\n";
            std::cout << "1. Console\n";
            std::cout << "2. File\n";
            std::cout << "3. Console and file\n";
            choice = ' ';
            while(choice != '1' && choice != '2' && choice != '3'){
                std::cin >> choice;
            };
            if (choice == '1')
                logger->addStream("console");
            if (choice == '2')
                logger->addStream("file");
            if (choice == '3'){
                logger->addStream("console");
                logger->addStream("file");
            }            
            std::cout << "What levels do you like to log?\n";
            std::cout << "1. Errors\n";
            std::cout << "2. Errors and main info\n";
            std::cout << "3. Errors, main info and game info\n";
            choice = ' ';
            while(choice != '1' && choice != '2' && choice != '3'){
                std::cin >> choice;
            };
            if (choice == '1')
                logger->addLevel(Error);
            if (choice == '2'){
                logger->addLevel(Error);
                logger->addLevel(Info);
            }
            if  (choice == '3'){
                logger->addLevel(Error);
                logger->addLevel(Info);
                logger->addLevel(Game);
            }
        }
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
                    if(logger->logging(Error) == true){
                       logger->printLog(Error, "Wrong data entered!\n");
                    }
                }else{
                    field = Field(true, x, y, player_x, player_y);
                    break;
                }
            }
        }

            field.getField()[0][1].changeAccess(false);
            if(logger->logging(Info) == true){
                logger->printLog(Info, "Access changed\n");
            }
            field.getField()[1][7].changeAccess(false);
            field.getField()[2][1].changeAccess(false);
            field.getField()[2][2].changeAccess(false);
            field.getField()[2][3].changeAccess(false);
            field.getField()[4][5].changeAccess(false);
            field.getField()[6][7].changeAccess(false);
            field.getField()[8][9].changeAccess(false);
            field.getField()[9][8].changeAccess(false);

            Trap testTrap = Trap(field.getPlayer());
            if(logger->logging(Info) == true){
                logger->printLog(Info, "Event setted\n");
            }
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
            if(field.getPlayer()->retWinState() == WIN || field.getPlayer()->retWinState() == LOSE)
                break;
            std::cin >> cmd;
        }
        if(field.getPlayer()->retWinState() == WIN){
            if(logger->logging(Game) == true)
                logger->printLog(Game, "You won!\n");
        }else{
            if(logger->logging(Game) == true)
                logger->printLog(Game, "You lost!\n");
        }
        logger->printLog(Info, "Game finished\n");
        logger->clearLoggers();
    }

