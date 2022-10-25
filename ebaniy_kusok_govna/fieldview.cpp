
#include "fieldview.hpp"


    void FieldView::printField(Field& field){
        Cell** temp = field.getField();
        for(int i = 0; i < field.getHeight(); i++) {
            for (int j = 0; j < field.getWidth(); j++) {
                if(temp[i][j].isPassable()){
                    if(i == field.getPlayerY() && j == field.getPlayerX()){
                        std::cout << "[@]";
                    }else{
                        if(temp[i][j].haveEvent() == true){
                                    if (field.getPlayer()->retOverseer() == true){
                                        if(dynamic_cast<Win*>(temp[i][j].eventAccess()) != nullptr){
                                            std::cout << "[%]";
                                        }
                                        if(dynamic_cast<Trap*>(temp[i][j].eventAccess()) != nullptr){
                                            std::cout << "[X]";
                                        }
                                        if(dynamic_cast<Enemy*>(temp[i][j].eventAccess()) != nullptr){
                                            std::cout << "[T]";
                                        }
                                        if(dynamic_cast<Overseer*>(temp[i][j].eventAccess()) != nullptr){
                                            std::cout << "[O]";
                                        }
                                        if(dynamic_cast<Earthquake*>(temp[i][j].eventAccess()) != nullptr){
                                            std::cout << "[^]";
                                        }
                                    }else
                                        std::cout << "[?]";
                        }
                        else{
                            std::cout << "[ ]";
                        }
                    }
                }
                else{
                    std::cout << "[#]";
                }
            }
            std::cout << '\n';
        }
    }
