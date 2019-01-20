#include <iostream>

#include "engine.h"
#include "window.h"

namespace sap
{
    Engine::Engine()
    {
        m_window = new io::Window(1080, 720, "Demo Application");
    }


    Engine::~Engine()
    {
        std::cout << "Engine destructor" << std::endl;
    }
}