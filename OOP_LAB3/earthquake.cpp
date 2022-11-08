#include "earthquake.hpp"
#include "field.hpp"

Earthquake* Earthquake::clone(){
        return new Earthquake(*this);
    }

void Earthquake::eventProc(){
    LogPool* logger = LogPool::getInstance();
    if(logger->logging(Game) == true)
        logger->printLog(Game, "You've stepped on some plate and ground started shaking!\n");
    //std::cout << "You've stepped on some plate and ground started shaking!";
        int player_x = field->getPlayerX();
        int player_y = field->getPlayerY();
        checkLeft(player_x, player_y);
        checkRight(player_x, player_y);
        checkDown(player_x, player_y);
        
    }

    void Earthquake::checkLeft(int x, int y){
        int size_x = field->getWidth();
        int size_y = field->getHeight();
        if(x-1 <= 0){
            if(field->getField()[y][size_x-1].haveEvent() != true){
                field->getField()[y][size_x-1].changeAccess(false);
            }
        }else{
            if(field->getField()[y][x-1].haveEvent() != true){
                field->getField()[y][x-1].changeAccess(false);
            }
        }
    };

    void Earthquake::checkRight(int x, int y){
        int size_x = field->getWidth();
        int size_y = field->getHeight();
        if(x+1 >= size_x){
            if(field->getField()[y][0].haveEvent() != true){
                field->getField()[y][0].changeAccess(false);
            }
        }else{
            if(field->getField()[y][x+1].haveEvent() != true){
                field->getField()[y][x+1].changeAccess(false);
            }
        }
    }

    void Earthquake::checkDown(int x, int y){
        int size_x = field->getWidth();
        int size_y = field->getHeight();
        if(y+1 == size_y){
            if(field->getField()[0][x].haveEvent() != true){
                field->getField()[0][x].changeAccess(false);
            }
        }else{
            if(field->getField()[y+1][x].haveEvent() != true){
                field->getField()[y+1][x].changeAccess(false);
            }
        }
    }