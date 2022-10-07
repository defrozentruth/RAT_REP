    #include "earthquake.hpp"
    
    void Earthquake::changePlayer(Player& player/*, Field& field*/){
        std::cout << "You've stepped on some plate and ground started shaking!";
        if(player.retAgility() >= agilityCheck){
            std::cout << "Somehow, you've managed to evade rocks that were falling from the ceiling. You've gained to your agility.\n";
            player.incAgility(lvl);            
        }else{
            std::cout << "While rocks were falling from above one had hit your head and you've lost some HP. Ouch.\n";
            player.decHP(lvl);
        }
        std::cout << "Some paths may be blocked now\n";
        // Cell** map = field.getField();
        // int player_x = field.getPlayerX();
        // int player_y = field.getPlayerY();
        // int size_x = field.getWidth();
        // int size_y = field.getHeight();
        // if(player_x+1 >= size_x){
        //     if(map[player_y][0].haveEvent() != true || map[player_y][0].eventAccess()->retName() != 'W'){
        //         map[player_y][0].changeAccess(false);
        //     }
        // }else{
        //     if(map[player_y][player_x+1].haveEvent() != true || map[player_y][player_x+1].eventAccess()->retName() != 'W'){
        //         map[player_y][player_x+1].changeAccess(false);
        //     }
        // }

        // if(player_x-1 <= 0){
        //     if(map[player_y][size_x-1].haveEvent() != true || map[player_y][size_x-1].eventAccess()->retName() != 'W'){
        //         map[player_y][size_x-1].changeAccess(false);
        //     }
        // }else{
        //     if(map[player_y][player_x-1].haveEvent() != true || map[player_y][player_x-1].eventAccess()->retName() != 'W'){
        //         map[player_y][player_x-1].changeAccess(false);
        //     }
        // }

        // if(player_y+1 == size_y){
        //     if(map[0][player_x].haveEvent() != true || map[0][player_y].eventAccess()->retName() != 'W'){
        //         map[0][player_x].changeAccess(false);
        //     }
        // }else{
        //     if(map[player_y+1][player_x].haveEvent() != true || map[player_y+1][player_x].eventAccess()->retName() != 'W'){
        //         map[player_y+1][player_x].changeAccess(false);
        //     }
        // }
        
    }
    void Earthquake::testEx(){
        std::cout << "trap exists\n";
    }

    char Earthquake::retName(){
        return 'Q';
    }

    Earthquake* Earthquake::clone(){
        return new Earthquake(*this);
    }