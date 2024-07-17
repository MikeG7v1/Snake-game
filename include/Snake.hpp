#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP
#include <vector>
enum class Control{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
class Snake {
protected:
    Control direction; // kierunek węża
    std::pair<int,int> head; // głowa węża
    int L; // dlugosc weza
    std::vector<std::pair<int,int>> tail;

public:

    const std::pair<int,int> getHead();
    int getL();
    void eaten();
    const std::vector<std::pair<int,int>> & getTail();
    void tailUpdate();
    void headUpdate(int height, int width);
    void modifyPosition(int height, int width);
    bool checkWin();
    virtual void move() = 0;
    virtual ~Snake();
};


#endif //SNAKE_SNAKE_HPP
