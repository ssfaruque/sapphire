#ifndef ENGINE_H
#define ENGINE_H


namespace sap {namespace io {class Window;}}

namespace sap
{
    class Engine
    {
        private:
            io::Window* m_window;

        public:
            Engine();
            ~Engine();

    };
}


#endif  // ENGINE_H
