#ifndef SNAKE_AI_HPP
#define SNAKE_AI_HPP
#include "Player.hpp"
#include <random>
#include "Food.hpp"
#include <vector>

class AI : public Player {
private:
    int choice;
    std::vector<int> path;
    std::vector<bool> options;
    Control random(Control option);
public:
    AI(int choice);
    void scan(std::vector<std::vector<char>> tab,int height, int width);
    void findShortestp(Food& Food);
    void move() override;
    bool checkColision();

};


#endif //SNAKE_AI_HPP
