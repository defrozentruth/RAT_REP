
#include "controller.hpp"
        void Controller::mover(Commands cmd, Field& field){
                switch (cmd){
                case Up:
                    std::cout << "Case Up " << cmd << '\n';
                    field.movePlayer(0, -1);
                break;
                case Left:
                    std::cout << "Case Left " << cmd << '\n';
                    field.movePlayer(-1, 0);
                break;
                case Down:
                std::cout << "Case Down " << cmd << '\n';
                    field.movePlayer(0, 1);
                break;
                case Right:
                std::cout << "Case Right " << cmd << '\n';
                    field.movePlayer(1, 0);
                break;
                default:
                std::cout << "Cringe " << cmd << '\n';
                    break;
                }
        }
