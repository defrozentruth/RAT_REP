#include "cell.hpp"


        Cell::Cell(bool access, bool playerOn, Event* event){
            this->access = access;
            this->event = event;
            this->playerOn = playerOn;
        }

        void Cell::changeEvent(Event* event){
            this->event = event;
        };

        void Cell::changeAccess(bool new_access){
            this->access = new_access;
        }

        bool Cell::isPassable(){
            return access;
        }

        void Cell::playerVisit(){
            if(playerOn)
                //EVENT PROC
                playerOn = false;
            else
                playerOn = true;
        }

        void Cell::swap(Cell &obj){
            std::swap(access, obj.access);
            std::swap(playerOn, obj.playerOn);
            std::swap(event, obj.event);
        }
        Cell& Cell::operator=(Cell& obj){
            if(this != &obj){
                Cell(obj).swap(*this);
            }
            return *this;
        }