
#include "field.hpp"

        Field::Field(int x, int y){
            LogPool* logger = LogPool::getInstance();
            this->size_x = x;
            this->size_y = y;
            this->map = new Cell*[size_y];
            for (int i = 0; i < size_y; i++){
                this->map[i] = new Cell[size_x];
            }
            this->player = new Player();
            if (logger->logging(Info) == true){
                logger->printLog(Info, "Field initialized\n");
            }
            
        }

        void Field::movePlayer(int x, int y){ 
            LogPool* logger = LogPool::getInstance();
            map[player_y][player_x].playerVisit(); 
            if(player_x == 0 && x == -1){
                if(map[player_y][size_x-1].isPassable()){
                    player_x = size_x - 1;
                    if (map[player_y][player_x].haveEvent() == true){
                        map[player_y][player_x].eventAccess()->eventProc();
                        map[player_y][player_x].changeEvent(nullptr);
                        map[player_y][player_x].changeEventPresence(false);
                    }
                }
                else
                    if(logger->logging(Error) == true)
                    logger->printLog(Error, "Cell isn't passable\n");
            }else
            if(player_y == 0 && y == -1){
                if(map[size_y-1][player_x].isPassable())
                    {player_y = size_y - 1;
                    if (map[player_y][player_x].haveEvent() == true){
                        map[player_y][player_x].eventAccess()->eventProc();
                        map[player_y][player_x].changeEvent(nullptr);
                        map[player_y][player_x].changeEventPresence(false);
                    }
                    }
                else
                    if(logger->logging(Error) == true)
                    logger->printLog(Error, "Cell isn't passable\n");
            }else
            if(player_x == size_x-1 && x == 1){
                if(map[player_y][0].isPassable())
                    {player_x = 0;
                    if (map[player_y][player_x].haveEvent() == true){
                        map[player_y][player_x].eventAccess()->eventProc();
                        map[player_y][player_x].changeEvent(nullptr);
                        map[player_y][player_x].changeEventPresence(false);
                    }}
                else
                    if(logger->logging(Error) == true)
                    logger->printLog(Error, "Cell isn't passable\n");
            }else
            if(player_y == size_y-1 && y == 1){
                if(map[0][player_x].isPassable())
                {    player_y = 0;
               if (map[player_y][player_x].haveEvent() == true){
                        map[player_y][player_x].eventAccess()->eventProc();
                        map[player_y][player_x].changeEvent(nullptr);
                        map[player_y][player_x].changeEventPresence(false);
                    }}
                else
                    if(logger->logging(Error) == true)
                    logger->printLog(Error, "Cell isn't passable\n");
            }else{
                if(map[player_y+y][player_x+x].isPassable()){
                    player_x += x;
                    player_y += y;
                    if (map[player_y][player_x].haveEvent() == true){
                        map[player_y][player_x].eventAccess()->eventProc();
                        map[player_y][player_x].changeEvent(nullptr);
                        map[player_y][player_x].changeEventPresence(false);
                    }
                }else
                    if(logger->logging(Error) == true)
                    logger->printLog(Error, "Cell isn't passable\n");
            }
            map[player_y][player_x].playerVisit();
        };
        Cell** Field::getField(){
            return map;
        }
        int Field::getHeight(){
            return size_y;
        }
        int Field::getWidth(){
            return size_x;
        }
        int Field::getPlayerX(){
            return player_x;
        }
        int Field::getPlayerY(){
            return player_y;
        }

        void Field::setPlayerX(int x){
            this->player_x = x;
        }

        void Field::setPlayerY(int y){
            this->player_y = y;
        }

        Player* Field::getPlayer(){
            return player;
        }
 
void Field::swap(Field &fieldObj){
    std::swap(size_y, fieldObj.size_y);
    std::swap(size_x, fieldObj.size_x);
    std::swap(map, fieldObj.map);
    std::swap(player_x, fieldObj.player_x);
    std::swap(player_y, fieldObj.player_y);
}

Field::Field(const Field& fieldObj){
    if(this != &fieldObj){
        this->size_x = fieldObj.size_x;
        this->size_y = fieldObj.size_y;
        this->player_x = fieldObj.player_x;
        this->player_y = fieldObj.player_y;
        for (int i = 0; i < size_y; i++){
            for (int j = 0; j < size_x; j++){
                this->map[i][j] = fieldObj.map[i][j];
            }
        }
    }
}
 
Field& Field::operator=(const Field& fieldObj){
    if(this != &fieldObj){
        Field(fieldObj).swap(*this);
    }
    return *this;
}
 
Field::Field(Field&& fieldObj){
    this->swap(fieldObj);
};
 
Field& Field::operator=(Field&& filedObj) {
    if (this != &filedObj)
        this->swap(filedObj);
    return *this;
};