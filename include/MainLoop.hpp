#ifndef SNAKE_MAINLOOP_HPP
#define SNAKE_MAINLOOP_HPP
#include "Game.hpp"

enum class Difficulty{
    SOLO,
    EASY,
    MEDIUM,
    GODMODE
};
class MainLoop {
private:
    Difficulty mode;
    int width;
    int height;
public:
    void showBoard(Game& game,Snake& AI, Snake& Player);
    MainLoop(int width, int height, Difficulty mode);
    void mainLoop();
    float speedChoice();
    void endingBanner(Ending info);
};


#endif //SNAKE_MAINLOOP_HPP
