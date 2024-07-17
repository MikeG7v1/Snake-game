#include "../include/AI.hpp"

AI::AI(int choice): choice{choice} {
    tail.reserve(100);
    path.reserve(2);
    for (int i = 0; i < 100; i++)
    {
        std::pair<int,int> temp;
        temp.first = 0;
        temp.second = 0;
        tail.push_back(temp);
    }
    for(int i=0; i<2; i++){
        path.push_back(0);
    }
    options.reserve(8);
    for(int i=0; i < 9; i++){
        options.push_back(false);
    }
    head.first = 11;
    head.second = 11;
    L=2;
    tail[0].first = 11;
    tail[0].second = 12;
}

void AI::findShortestp(Food &Food) {
    int xmod,ymod;
    xmod = (Food.getPosX() - head.first);
    ymod = (Food.getPosY() - head.second);
    path[0] = xmod;
    path[1] = ymod;
}

void AI::scan(std::vector<std::vector<char>> tab,int height, int width) {
    for(int i=0; i < 9; i++){
        options[i] = false;
    }
    int X1,X2,X3,X4,X5,X6,X7,X8,Y1,Y2,Y3,Y4,Y5,Y6,Y7,Y8;

    X1 = (head.first - 1 + height)%height;
    Y1 = (head.second - 1 + width)%width;

    X2 = (head.first - 1 + height)%height;
    Y2 = (head.second + width)%width;

    X3 = (head.first - 1 + height)%height;
    Y3 = (head.second + 1 + width)%width;

    X4 = (head.first + height)%height;
    Y4 = (head.second - 1 + width)%width;

    X5 = (head.first + height)%height;
    Y5 = (head.second + 1 + width)%width;

    X6 = (head.first + 1 + height)%height;
    Y6 = (head.second - 1 + width)%width;

    X7 = (head.first + 1 + height)%height;
    Y7 = (head.second + width)%width;

    X8 = (head.first + 1 + height)%height;
    Y8 = (head.second + 1 + width)%width;

    if((tab[X1][Y1] == '-') or (tab[X1][Y1] == 'o'))
    {
        options[0] = true;
    }
    if((tab[X2][Y2] == '-') or (tab[X2][Y2] == 'o'))
    {
        options[1] = true;
    }
    if((tab[X3][Y3] == '-') or (tab[X3][Y3] == 'o'))
    {
        options[2] = true;
    }
    if((tab[X4][Y4] == '-') or (tab[X4][Y4] == 'o'))
    {
        options[3] = true;
    }
    if((tab[X5][Y5] == '-') or (tab[X5][Y5] == 'o'))
    {
        options[4] = true;
    }
    if((tab[X6][Y6] == '-') or (tab[X6][Y6] == 'o'))
    {
        options[5] = true;
    }
    if((tab[X7][Y7] == '-') or (tab[X7][Y7] == 'o'))
    {
        options[6] = true;
    }
    if((tab[X8][Y8] == '-') or (tab[X8][Y8] == 'o'))
    {
        options[7] = true;
    }
}

Control AI::random(Control option) {
    int level;
    switch(choice)
    {
        case 1:
            level = 200;
            break;
        case 2:
            level = 300;
            break;
        case 3:
            level = 400;
            break;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 400);
    int number = distr(gen);

    if(number < level){
        return option;
    }
    else{
        if((option != Control::DOWN) and (number < (level + 0.25 *(400 - level)))){
            option = Control::UP;
            return option;
        }
        else if((option != Control::UP) and (number < ((level + 0.50 *(400 -level))))){
            option = Control::DOWN;
            return option;
        }
        else if((option != Control::LEFT) and (number < (level + 0.75 *(400 -level)))){
            option = Control::DOWN;
            return option;
        }
        else if (option != Control::DOWN){
            option = Control::LEFT;
            return option;
        }
        else{
            return option;
        }

    }
}

void AI::move() {
    if(path[0] < 0){
        if(options[1]){
            direction = Control::UP;
            direction = random(Control::UP);
            return;
        }
        else if(options[3]){
            direction = Control::LEFT;
            direction = random(Control::LEFT);
            return;
        }
        else if(options[4]){
            direction = Control::DOWN;
            direction = random(Control::DOWN);
            return;
        }
        else{
            direction = Control::UP;
            return;
        }
    }
    else if(path[0] > 0){
        if(options[6]){
            direction=Control::DOWN;
            direction = random(Control::DOWN);
            return;
        }
        else if(options[3]){
            direction = Control::LEFT;
            direction = random(Control::LEFT);
            return;
        }
        else if (options[4]){
            direction = Control::DOWN;
            direction = random(Control::DOWN);
            return;
        }
        else{
            direction = Control::DOWN;
            return;
        }
    }
    else if(path[1] < 0){
        if(options[3]){
            direction = Control::LEFT;
            direction = random(Control::LEFT);
            return;
        }
        if(options[1]){
            direction = Control::UP;
            direction = random(Control::UP);
            return;
        }
        else if(options[6]){
            direction = Control::DOWN;
            direction = random(Control::DOWN);
            return;
        }
        else{
            direction = Control::LEFT;
            return;
        }
    }
    else if(path[1] > 0){
        if(options[4]){
            direction = Control::DOWN;
            direction = random(Control::DOWN);
            return;
        }
        else if(options[1]){
            direction = Control::UP;
            direction = random(Control::UP);
            return;
        }
        else if(options[6]){
            direction = Control::DOWN;
            direction = random(Control::DOWN);
            return;
        }
        else{
            direction = Control::DOWN;
        }
    }
}

bool AI::checkColision() {

    for(int i= 0; i < L ; i++)//sprawdzanie zderzenia głowy AI z ogonem AI
    {
        if ((head.first == tail[i].first) and (head.second == tail[i].second )){
            return true;
        }
    }
    return false;
}