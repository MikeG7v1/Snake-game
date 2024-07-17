#include "../include/MainLoop.hpp"
int main()
{

    int choice;
    while(true)
    {
        system("cls");
        std::cout<< "GAME MODE:\n\n SINGLE-PLAYER (1) \n\n PLAYER VS AI (10 points to win): \n\n EASY (2)\n MEDIUM (3)\n HARD (4) \n\n TWOJ WYBOR: ";
        std::cin >>  choice;

        int size, height, width;
        std::cout << "BOARD SIZE: SMALL(1)\t MEDIUM(2)\t LARGE(3)\n TWOJ WYBOR: ";
        std::cin >> size;
        switch(size)
        {
            case 1:
                height = 10;
                width = 10;
                break;
            case 2:
                height = 15;
                width = 15;
                break;
            case 3:
                height = 20;
                width = 20;
                break;

        }
        if((choice != 1) and (choice != 2) and (choice != 3) and (choice != 4))
        {
            std::cout<< " \nPICK PROPPER VALUE !!!\n";
            continue;
        }
        if(choice == 1){
            MainLoop MainLoop(height, width, Difficulty::SOLO);
            MainLoop.mainLoop();
        }
        else if(choice == 2){
            MainLoop MainLoop(height, width, Difficulty::EASY);
            MainLoop.mainLoop();
        }
        else if (choice == 3){
            MainLoop MainLoop(height, width, Difficulty::MEDIUM);
            MainLoop.mainLoop();
        }
        else if (choice == 4){
            MainLoop MainLoop(height, width, Difficulty::GODMODE);
            MainLoop.mainLoop();
        }
        std::cout<<"\n\nPLAY AGAIN ? YES(1) NO(2)\n";
        std::cin >> choice;
        if (choice == 1){
            continue;
        }
        else{
            break;
        }
    }


    return 0;
}

