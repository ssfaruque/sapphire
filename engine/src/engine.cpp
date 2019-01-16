#include "engine.h"

#include <iostream>

namespace sap
{
    Engine::Engine()
    {

    }

    Engine::~Engine()
    {
        std::cout << "Engine destructor" << std::endl;
    }
}