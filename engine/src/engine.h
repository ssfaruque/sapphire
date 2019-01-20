#ifndef ENGINE_H
#define ENGINE_H

#include "system.h"

namespace sap {namespace io {class Window;}}

namespace sap
{
    class Sapphire : public System
    {
        private:
            io::Window* m_window;
            bool m_running;

        public:
            Sapphire();
            ~Sapphire();

            void update() override;

            inline bool isRunning() const {return m_running;}

    };
}


#endif  // ENGINE_H
