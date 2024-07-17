#include "../include/Food.hpp"

Food::Food(){

    isOnMap = 1;
    posX = 0;
    posY = 4;
    apple = 'o';
}

int Food::getPosX() {
    return posX;
}

void Food::setPosX(int x) {
    posX = x;
}

int Food::getPosY() {
    return posY;
}

void Food::setPosY(int y) {
    posY = y;
}

char Food::getApple() {
    return apple;
}

void Food::setApple(char symbol) {
    apple = symbol;
}

int Food::getIsOnMap() {
    return isOnMap;
}

void Food::setIsOnMap(int value) {
    isOnMap = value;

}