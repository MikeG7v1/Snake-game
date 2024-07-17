#include "../include/Snake.hpp"
#include "windows.h"

const std::pair<int,int> Snake::getHead() {
    return head;
}

int Snake::getL() {
    return L;
}

void Snake::eaten() {
    L++;
    tailUpdate();
}

void Snake::tailUpdate() {
    for(int i = L-1; i >= 1 ; i--)
    {
        tail[i].first = tail[i-1].first;
        tail[i].second = tail[i-1].second;
    }
}

void Snake::modifyPosition(int height, int width){
    int m,n;
    switch(direction)
    {
        case Control::UP :
            m = ((head.first-1)+height)%height;
            n = head.second;
            if((m != tail[0].first) or (n != tail[0].second)){
                tail[0].first = head.first;
                tail[0].second = head.second;
                tailUpdate();
                head.first= head.first - 1;
            }
            else{
                tail[0].first = head.first;
                tail[0].second = head.second;
                tailUpdate();
                head.first= head.first + 1;
            }
            break;

        case Control::DOWN :
            m = ((head.first+1)+height)%height;
            n = head.second;
            if((m != tail[0].first) or (n != tail[0].second)){
                tail[0].first = head.first;
                tail[0].second = head.second;
                tailUpdate();
                head.first= head.first + 1;
            }
            else{
                tail[0].first = head.first;
                tail[0].second = head.second;
                tailUpdate();
                head.first= head.first - 1;
            }
            break;

        case Control::LEFT :
            m = head.first;
            n = ((head.second-1)+width)%width;
            if((m != tail[0].first) or (n != tail[0].second)){
                tail[0].first = head.first;
                tail[0].second = head.second;
                tailUpdate();
                head.second= head.second - 1;
            }
            else{
                tail[0].first = head.first;
                tail[0].second = head.second;
                tailUpdate();
                head.second= head.second + 1;
            }
            break;

        case Control::RIGHT :
            m = head.first;
            n = ((head.second+1)+width)%width;
            if((m != tail[0].first) or (n != tail[0].second)){
                tail[0].first = head.first;
                tail[0].second = head.second;
                tailUpdate();
                head.second= head.second + 1;
            }
            else{
                tail[0].first = head.first;
                tail[0].second = head.second;
                tailUpdate();
                head.second= head.second - 1;
            }
            break;
    }
}

const std::vector<std::pair<int,int>> &Snake::getTail() {
    return tail;
}


bool Snake::checkWin() {
    if((L - 2) == 10 )
    {
        return true;
    }
    else{
        return false;
    }
}

void Snake::headUpdate(int height, int width) {
    if(head.first >= height){
       head.first = 0;
    }
    else if(head.second >= width){
        head.second = 0;
    }
    else if(head.first < 0){
        head.first = (height - 1);
    }
    else if(head.second < 0){
        head.second = (width - 1);
    }
}
Snake::~Snake() { }