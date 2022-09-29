#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player{

public:

    Player(int HP = 100, int mana = 100, int power = 1):_hitPoints(HP), _mana(mana), _power(power){}
    Player(const Player& obj):_hitPoints(obj._hitPoints), _mana(obj._mana), _power(obj._power){}
    Player& operator=(const Player& obj);

    enum direction{
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3, 
        QUIT = 4
    };

    int getPower() const;

    void setPower(int power);
int _power;
private:
    int _hitPoints;
    int _mana;
    
    
};

#endif