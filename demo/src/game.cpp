#include "game.h"
#include "sapphire/sapphire.h"

Game::Game():
m_running(false)
{
    //sap::Engine engine;
    m_engine = new sap::Sapphire;
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
    m_running = true;

    while((m_running = m_engine->isRunning()))
    {
        m_engine->update();
    }
}


void Game::onUpdate()
{ 
    
}