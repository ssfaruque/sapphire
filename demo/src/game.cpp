#include "game.h"
#include "sapphire/engine.h"

Game::Game():
m_running(true)
{
    //sap::Engine engine;
    m_engine = new sap::Engine;
}

 
Game::~Game()
{
}


bool Game::init()
{
    return true;
}


void Game::shutDown()
{

}


void Game::run()
{

}


void Game::onUpdate()
{ 
}