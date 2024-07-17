#include "../include/MainLoop.hpp"
MainLoop::MainLoop(int width, int height, Difficulty mode)
    : height{height}, width{width}, mode{mode}{
}

float MainLoop::speedChoice() {
    int choice;
    float speed;
    while(true){
        std::cout << "CHOOSE SPEED 1-3: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                return speed = 600;
            case 2:
                return speed = 300;
            case 3:
                return speed = 100;
        }
        std::cout << "CHOOSE PROPER VALUE !!!!";
    }
}

void MainLoop::endingBanner(Ending info) {

    switch (info) {
        case Ending::LOOSE_P_hit_AI:
            std::cout << "GAME OVER: LOOSE - PLAYER HIT BOT \n";
            break;
        case Ending::LOOSE_P_hit_P:
            std::cout << "GAME OVER: LOOSE - YOU HIT OWN TAIL \n";
            break;
        case Ending::WIN_AI_hit_AI:
            std::cout << "GAME OVER: WIN - BOT HIT OWN TAIL \n";
            break;
        case Ending::WIN_AI_hit_P:
            std::cout << "GAME OVER: WIN - BOT HIT YOUR TAIL \n";
            break;
        case Ending::DRAW:
            std::cout << "GAME OVER: DRAW - HEAD HIT";
            break;
    }
}

void MainLoop::showBoard(Game &game, Snake &AI, Snake &Player) {
    game.updateBoard(AI);
    game.updateBoard(Player);
    game.render(AI,Player);
    std::cout<<" PLAYER POINTS: " << Player.getL() - 2 << "  " << " BOT POINTS: " << AI.getL() - 2 << "\n";
}

void MainLoop::mainLoop() {
    float speed = speedChoice();
    if (mode == Difficulty::SOLO){
        Player Player;
        Food Food;
        Game game(height,width);
        while(true){
            Player.setSpeed(speed);
            game.control(Player);
            game.clearBoard();
            game.printFood(Food);
            Player.headUpdate(height,width);
            Ending validation = game.checkLoose(Player,Player);
            if(validation != Ending::CONTINUE_GAME and validation != Ending::DRAW){
                game.updateBoard(Player);
                game.render(Player,Player);
                std::cout<<" PLAYER POINTS: " << Player.getL() - 2 <<" GAME OVER";
                break;
            }
            game.updateBoard(Player);
            game.isEaten(Player, Food);
            game.placeFood(Food);
            game.render(Player,Player);
            std::cout<<"POINTS: " << Player.getL() - 2;
        }
    }
    else{
        int difficulty;
        if (mode == Difficulty::EASY){
            difficulty = 1;
        }
        else if(mode == Difficulty::MEDIUM){
            difficulty = 2;
        }
        else if(mode == Difficulty::GODMODE){
            difficulty = 3;
        }

        AI AI(difficulty);
        Player Player;
        Food Food;
        Game game(height,width);
        bool running = true;
        Ending info;
        while (running) {
            Player.setSpeed(speed);
            game.control(Player);
            AI.findShortestp(Food);
            game.passBoard(AI);
            game.control(AI);
            game.clearBoard();
            game.printFood(Food);
            AI.headUpdate(height,width);
            Player.headUpdate(height,width);
            info = game.checkLoose(AI, Player);
            if(AI.checkColision())
            {
                info = Ending::WIN_AI_hit_AI;
                break;
            }
            if (info != Ending::CONTINUE_GAME) {
                showBoard(game,AI,Player);
                break;
            }
            if (AI.checkWin()) {
                showBoard(game,AI,Player);
                std::cout << "GAME OVER WINNER: AI";
                break;
            }
            if (Player.checkWin()) {
                showBoard(game,AI,Player);
                std::cout << "GAME OVER WINNER: PLAYER";
                break;
            }
            game.updateBoard(AI);
            game.updateBoard(Player);
            game.isEaten(Player, Food);
            game.isEaten(AI, Food);
            game.placeFood(Food);
            game.render(AI,Player);
            std::cout<<" PLAYER POINTS: " << Player.getL() - 2 << "  " << " BOT POINTS: " << AI.getL() - 2 << "\n";
        }

        endingBanner(info);
    }
}
