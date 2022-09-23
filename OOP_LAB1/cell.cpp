#include "cell.hpp"


        Cell::Cell(int x, int y, bool access, bool playerOn, Event* event){
            this->x = x;
            this->y = y;
            this->access = access;
            this->event = event;
            this->playerOn = playerOn;
        }

        // Cell::Cell(Cell& obj):x(obj.x), y(obj.y), access(obj.access), event(obj.event){
        // }
        Cell& Cell::operator =(Cell& obj){
            if (this != &obj){
                this->x = obj.x;
                this->y = obj.y;
                this->access = obj.access;
                this->event = obj.event;
            }
            return *this;
        }

        void Cell::accessChanger(bool access){
            this->access = access;
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
                playerOn = false;
            else
                playerOn = true;
        }