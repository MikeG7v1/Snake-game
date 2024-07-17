#ifndef SNAKE_FOOD_HPP
#define SNAKE_FOOD_HPP


class Food {
private:
    int posX;
    int posY;
    char apple;
    int isOnMap;
public:
    Food();
    int getPosX();
    void setPosX(int x);
    int getPosY();
    void setPosY(int y);
    char getApple();
    void setApple(char symbol);
    int getIsOnMap();
    void setIsOnMap(int value);

};


#endif //SNAKE_FOOD_HPP
