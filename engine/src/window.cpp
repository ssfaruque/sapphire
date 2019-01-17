#include <iostream>

#include "GLFW/glfw3.h"

#include "window.h"


namespace sap::io
{
    Window::Window()
    {
        if(glfwInit() == GLFW_TRUE)
        {
            std::cout << "Successfully initialized glfw" << std::endl;
        }
        std::cout << "Constructed Window" << std::endl;
    }


    Window::~Window()
    {
        
    }

}