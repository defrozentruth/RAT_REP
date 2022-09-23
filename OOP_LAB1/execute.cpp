#include "execute.hpp"


    void Execute::run(){
        int x,y, player_x, player_y;
        char cmd;
        int hp, armor, agility;
        std::cin >> hp >> armor >> agility;
        Player player(hp, armor, agility);
        std::cin >> x >> y >> player_x >> player_y;
        Field field(x, y, player_x, player_y);
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

