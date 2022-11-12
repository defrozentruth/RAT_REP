
#include "controller.hpp"
        void Controller::mover(char movement, Field& field){
                movement = tolower(movement);
                switch (movement){
                case 'w':
                    field.movePlayer(0, -1);
                break;
                case 'a':
                    field.movePlayer(-1, 0);
                break;
                case 's':
                    field.movePlayer(0, 1);
                break;
                case 'd':
                    field.movePlayer(1, 0);
                break;
                }
        }
