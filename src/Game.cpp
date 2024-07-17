#include "../include/Game.hpp"
//#include <curses.h>
//#include <termios.h>


Game::Game(int height, int width)
        : height {height}, width {width}{

    tab.reserve(height*width);
    int x='-';
    for (int i = 0; i < height; i++)
    {
        std::vector<char> temp;
        temp.reserve(width);
        for (int j = 0; j < width; j++)
        {
            temp.push_back(x);
        }
        tab.push_back(temp);
    }
}

void Game::placeFood(Food &food1){// losowe ustawienie jedzenia
    int x,y;
    if(food1.getIsOnMap() == 0) {
        while (true) {
            x = rand() % (height - 1);
            y = rand() % (width - 1);
            if (tab[x][y] == '-') {
                food1.setPosX(x);
                food1.setPosY(y);
                break;
            } else
                continue;
        }
        food1.setIsOnMap(1);
    }
}

void Game::isEaten(Snake &Snake,Food &food1){ //sprawdzanie czy któryś z węży zjadł jedzenie
    if(Snake.getHead().first == food1.getPosX() and Snake.getHead().second == food1.getPosY()){
        food1.setIsOnMap(0);
        Snake.eaten();
    }

}

void Game::clearBoard() {// czyszczenie tablicy przed zaktualizowaniem do stanu obecnego
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            tab[i][j] = '-';
        }
    }
}

void Game::printFood(Food &food1) { //umieszczanie jedzenia na tablicy
    if(food1.getIsOnMap() == 1){
        tab[food1.getPosX()][food1.getPosY()] = food1.getApple();
    }
}

void Game::updateBoard(Snake& Snake) { // aktualizowanie stanu węży na tablicy

    int x,y;
    for(int i=0; i < Snake.getL(); i++){
        x = Snake.getTail()[i].first;
        y = Snake.getTail()[i].second;
        tab[x][y] = '#';
    }
    tab[Snake.getHead().first][Snake.getHead().second] = '@';
}

Ending Game::checkLoose(Snake &AI,Snake &Player) { // sprawdzenie czy gracz lub bot przegrali


    for(int i =0; i < AI.getL(); i++)//sprawdzanie zderzenia głowy Player z ogonem AI
    {
        if ((Player.getHead().first == AI.getTail()[i].first) and (Player.getHead().second == AI.getTail()[i].second)){
            return Ending::LOOSE_P_hit_AI;
        }
    }

    if ((Player.getHead().first == AI.getHead().first) and (Player.getHead().second == AI.getHead().second)){// sprawdzanie zderzenia głową
        return Ending::DRAW;
    }

    for(int i = 0; i < Player.getL(); i++)//sprawdzanie zderzenia głowy Player z ogonem Player
    {
        if ((Player.getHead().first == Player.getTail()[i].first) and (Player.getHead().second == Player.getTail()[i].second)){
            return Ending::LOOSE_P_hit_P;
        }
    }

    for(int i =0; i < Player.getL(); i++)//sprawdzanie zderzenia głowy AI z ogonem Player
    {
        if ((AI.getHead().first == Player.getTail()[i].first) and (AI.getHead().second == Player.getTail()[i].second )){
            return Ending::WIN_AI_hit_P;
        }
    }

    return Ending::CONTINUE_GAME;
}

void Game::render(Snake& AI, Snake& Player) { // wyświetlanie aktualnego stanu tablicy na ekranie
    system("cls");
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            std::cout << " " << tab[i][j];
        }
        std::cout<<"\n";
    }
}

void Game::control(Snake& Snake) { //wykonanie ruchu przez węża
    Snake.move();
    Snake.modifyPosition(height,width);
}

void Game::passBoard(AI &AI) {
        AI.scan(tab,height,width);
}