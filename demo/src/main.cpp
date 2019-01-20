#include <iostream>

#include "game.h"

int main(int argc, char** argv)
{
    Game* game = new Game;
    
    game->init();
    game->run();
    game->shutDown(); 

    return 0;
}