#include <iostream>

#include "engine.h"
#include "window.h"

namespace sap
{
    Engine::Engine()
    {
        m_window = new io::Window;
    }

    Engine::~Engine()
    {
        std::cout << "Engine destructor" << std::endl;
    }
}