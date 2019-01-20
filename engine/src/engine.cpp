#include <iostream>

#include "engine.h"
#include "window.h"

namespace sap
{
    Sapphire::Sapphire():
    m_running(true)
    {
        m_window = new io::Window(1080, 720, "Demo Application");
    }


    Sapphire::~Sapphire()
    {
        std::cout << "Shutting down Sapphire engine..." << std::endl;
    }

    void Sapphire::update()
    {
        m_window->update();

        if(m_window->isClosed())
            m_running = false;
    }



}