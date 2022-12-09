#include "execute.hpp"


    void Execute::run(){
        LogPool* logger = LogPool::getInstance();
        int x,y;
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
        FieldGen generator;
        choice = ' ';
        std::cout << "Which level do you want?\n1. 5x5 field\n2. 20x20 field\n";
        while(choice != '1' && choice != '2' && choice != 'A'){
            std::cin >> choice;
        };
        if (choice == '1'){
            generator.setLevel(First);
        }
        if (choice == '2'){
            generator.setLevel(Second);
        }
        if (choice == 'A'){
            logger->printLog(Error, "SUS AMOGUS DETECTED\n");
            generator.setLevel(Test);
        }
        Field* field = generator.create();
        FileSettingsRead commands;
        ConsoleCmdRead cmdReader(commands.getDirections());
        Commands cmd;
        Controller contr;
        FieldView fview;
        system("clear");
        fview.printField(*field);
        std::cout << "HP: " << field->getPlayer()->retHP() << " Agility: " << field->getPlayer()->retAgility() << " Attack: " << field->getPlayer()->retAttack() << " Score: "<< field->getPlayer()->retScore() <<'\n';
        cmd = cmdReader.readCmd();
        while(cmdReader.getExitState() != true && field->getPlayer()->retWinState() != WIN && field->getPlayer()->retWinState() != LOSE){
            system("clear");
            contr.mover(cmd, *field);
            std::cout << '\n';
            fview.printField(*field);
            std::cout << "HP: " << field->getPlayer()->retHP() << " Agility: " << field->getPlayer()->retAgility() << " Attack: " << field->getPlayer()->retAttack() << " Score: "<< field->getPlayer()->retScore()<< '\n';
            if(field->getPlayer()->retWinState() == WIN || field->getPlayer()->retWinState() == LOSE)
                break;
            cmd = cmdReader.readCmd();
        }
        if(field->getPlayer()->retWinState() == WIN){
            if(logger->logging(Game) == true)
                logger->printLog(Game, "You won!\n");
        }else{
            if(logger->logging(Game) == true)
                logger->printLog(Game, "You lost!\n");
        }
        logger->printLog(Info, "Game finished\n");
        logger->clearLoggers();
    }

