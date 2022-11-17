
#include "controller.hpp"
        void Controller::mover(Commands cmd, Field& field){
                switch (cmd){
                case Up:
                    field.movePlayer(0, -1);
                break;
                case Left:
                    field.movePlayer(-1, 0);
                break;
                case Down:
                    field.movePlayer(0, 1);
                break;
                case Right:
                    field.movePlayer(1, 0);
                break;
                default:
                    break;
                }
        }
