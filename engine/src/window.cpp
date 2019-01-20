#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"




#include "window.h"


namespace sap::io
{



    void errorCallback(int error, const char* description)
    {

    }



    void Window::registerCallbacks()
    {
        glfwSetErrorCallback(errorCallback);
    }


    Window::Window(int width, int height, const std::string& title):
    m_closed(false)
    {
        if(glfwInit() != GLFW_TRUE)
        {
            std::cout << "Failed to initialize glfw" << std::endl;
        }

        spdlog::info("Initialized glfw");

        m_windowProperties = {width, height, title};

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if(!m_window)
        {
            std::cout << "Failed to create window" << std::endl;
        }   

        glfwMakeContextCurrent(m_window); 

        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    }


    Window::~Window()
    {
        if(m_window)
        {
            glfwDestroyWindow(m_window);
        }


        glfwTerminate();
    }


    int Window::getWidth() const
    {
        return m_windowProperties.m_width;
    }


    int Window::getHeight() const
    {
        return m_windowProperties.m_height;
    }


    std::string Window::getTitle() const
    {
        return m_windowProperties.m_title;
    }


    void Window::update()
    {
    }

}