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
            std::cerr << "Failed to initialize glfw" << std::endl;
        }

        m_windowProperties = {width, height, title};

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if(!m_window)
        {
            std::cerr << "Failed to create window" << std::endl;
        }   

        glfwMakeContextCurrent(m_window); 

        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        glfwSwapInterval(1);
    }


    Window::~Window()
    {
        if(m_window)
        {
            glfwDestroyWindow(m_window);
        }

        glfwTerminate();
    }


    void Window::update()
    {
        glfwPollEvents();

        if(glfwWindowShouldClose(m_window))
            m_closed = true;
        
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glfwSwapBuffers(m_window);
    }

}