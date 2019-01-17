#include <iostream>
#include <dlfcn.h>

#include "game.h"

int main(int argc, char** argv)
{
    

    Game* game = new Game;

    std::cout << "Hello World!" << std::endl;

    game->run();

    return 0;
}