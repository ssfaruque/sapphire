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

            inline int getWidth() const;
            inline int getHeight() const;
            inline std::string getTitle() const;

            void update() override;
    };
}






#endif  // WINDOW_H