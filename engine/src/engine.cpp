#include <iostream>

#include "engine.h"
#include "window.h"


// INCLUDES FOR TESTING
#include "shader.h"
//

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

        float data[] = {-0.5f, -0.5f, 0.0f,
                        0.5f, -0.5f, 0.0f,
                        0.0f,  0.5f, 0.0f};

        unsigned int vbo, vao;
        glGenBuffers(1, &vbo);
        glGenVertexArrays(1, &vao);

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(0);

        gfx::Shader shader("../engine/data/shaders/simple.vsh", "../engine/data/shaders/simple.fsh");
        shader.bind();

        glBindVertexArray(vao);

        glDrawArrays(GL_TRIANGLES, 0, 3);



    }
}