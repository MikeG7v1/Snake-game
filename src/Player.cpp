#include "../include/Player.hpp"
#include <iostream>

Player::Player(){
    direction = Control::RIGHT;
    tail.reserve(100);
    for (int i = 0; i < 100; i++){
        std::pair<int,int> temp;
        temp.first = 0;
        temp.second = 0;
        tail.push_back(temp);
    }
    head.first = 0; // tymczasowe koordynaty do zmiany przy organizowaniu presetów
    head.second = 7;
    L=2;
    tail[0].first= 0;
    tail[0].second = 6;

}

void Player::setSpeed(float value) {
    speed = value;
}

void Player::move() {
    char input;
    float delta;
    while (true)//wczytywanie z klawiatury temporary
    {
        if (_kbhit()) {
            input = _getch();

            if ((direction == Control::UP and input == 's') or (direction == Control::DOWN and input == 'w') or (direction == Control::LEFT and input == 'd') or (direction == Control::RIGHT and input == 'a')) {
                continue;
            }
            if (input == 'w' or input == 'd' or input == 's' or input == 'a') {

                break;
            }
        }
        cur = GetTickCount();
        delta = cur - last;
        if (delta > speed)
            break;
    }
    last = cur;
    switch(input)
    {
        case 'w':
            direction = Control::UP;
            break;
            //return Control::UP;
        case 's':
            direction = Control::DOWN;
            break;
            //return Control::DOWN;
        case 'a':
            direction = Control::LEFT;
            break;
            //return Control::LEFT;
        case 'd':
            direction = Control::RIGHT;
            break;
            //return Control::RIGHT;
    }

}
//Player::~Player() {}


