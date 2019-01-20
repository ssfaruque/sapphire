#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "system.h"

namespace sap::io
{
    class Window : public System
    {
        private:
            GLFWwindow* m_window;
            bool m_closed;

            struct WindowProperties
            {
                int m_width;
                int m_height;
                std::string m_title;
            } m_windowProperties;


        private:
            void registerCallbacks();

        public:
            Window(int width, int height, const std::string& title);
            ~Window();

            inline int getWidth() const {return m_windowProperties.m_width;}
            inline int getHeight() const {return m_windowProperties.m_height;}
            inline std::string getTitle() const {return m_windowProperties.m_title;}
            inline bool isClosed() const {return m_closed;}

            void update() override;
    };
}






#endif  // WINDOW_H