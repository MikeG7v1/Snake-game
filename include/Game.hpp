#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP
#include <vector>
#include <cstdlib>
#include "Snake.hpp"
#include "Food.hpp"
#include "iostream"
#include "AI.hpp"
enum class Ending{
    WIN_AI_hit_P,
    LOOSE_P_hit_AI,
    LOOSE_P_hit_P,
    WIN_AI_hit_AI,
    DRAW,
    CONTINUE_GAME
};
class Game {
private:
    int height;
    int width;
    std::vector <std::vector<char>> tab;
public:
    Game(int height, int width);
    void placeFood(Food& Food);
    void isEaten(Snake& Snake,Food &Food);
    void updateBoard(Snake& Snake);
    void clearBoard();
    void printFood(Food& Food);
    void control(Snake& Snake);
    Ending checkLoose(Snake& AI, Snake& Player);
    void render(Snake& AI, Snake& Player);
    void passBoard(AI& AI);
};


#endif //SNAKE_GAME_HPP
