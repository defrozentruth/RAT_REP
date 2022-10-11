#ifndef PLAYER_HPP
#define PLAYER_HPP

#define WIN 1
#define LOSE -1

class Player{
    int hp;
    int agility;
    int attack;
    int winState;
    bool overseer;
    int score;
    // int treasureX;
    // int treasureY;
    public:
        Player(int hp = 10, int agility = 1, int atk = 1);
        void decHP(int hp);
        void setHP(int hp);
        int retHP();
        int retAgility();
        int retAttack();
        void incHP(int hp);
        void incAgility(int ag);
        void incAttack(int atk);
        void changeWinState(int state);
        int retWinState();
        void changeOverseer(bool state);
        bool retOverseer();
        void addScore(int score);
        int retScore();
};

#endif