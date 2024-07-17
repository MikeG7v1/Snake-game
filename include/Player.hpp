#ifndef SNAKE_PLAYER_HPP
#define SNAKE_PLAYER_HPP
#include "Snake.hpp"
#include <windows.h>
#include <conio.h>


class Player: public Snake {
private:
    float last;
    float cur;
    float speed;
public :
    Player();
    void setSpeed(float value);
    void move() override;
};


#endif //SNAKE_PLAYER_HPP
