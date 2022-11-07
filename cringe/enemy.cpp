#include "enemy.hpp"


void Enemy::change_state(){
    attack();
    //this->notify();
}

void Enemy::attack(){
    if(player->getPower() > this->_power){
        player->addPoints(points_for_kill);//константная переменная 
        return;
    }else{
        player->setHP(player->getHP()+player->getPower()-this->_power);
        
        if(player->getHP() <= 0){
            // std::cout << "You`re dead!\n";
            field->changeState(Field::LOSE);
            return;
        }
        
        this->_hp -= player->getPower();
        defence();
        return;
    }
}

void Enemy::defence(){
    
    Enemy* new_state_enemy = new Enemy(this->player,this->field, this->_power, this->_hp);
    int old_x = field->player_x();
    int old_y = field->player_y();
    
    if(this->_hp < 0){
        player->addPoints(25);
    }else{
        
        goToEmptyCell(old_x, old_y);
        field->getField()[old_x][old_y].setEvent(new_state_enemy);
    }
    delete new_state_enemy;
}

Enemy* Enemy::clone(){
    return new Enemy(*this);
}

void Enemy::goToEmptyCell(int old_x, int old_y){
    if(field->getField()[old_y][old_x-1].getType() != Cell::IMPASSABLE){
            field->move(Player::LEFT);
        }else{
            if(field->getField()[old_y][old_x+1].getType() != Cell::IMPASSABLE){
                field->move(Player::RIGHT);
            }else{
                if(field->getField()[old_y-1][old_x].getType() != Cell::IMPASSABLE){
                    field->move(Player::DOWN);
                }else{
                    field->move(Player::UP);
                }
            }
        }
}