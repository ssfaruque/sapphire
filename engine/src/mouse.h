#ifndef MOUSE_H
#define MOUSE_H

namespace sap::io
{
    enum class MouseButton
    {
        LEFT,
        RIGHT,
        SCROLL,
        NUM_BUTTONS
    };

    class Mouse
    {
        private:
            static bool m_buttons[static_cast<int>(MouseButton::NUM_BUTTONS)];

        public:
            static void init();
            static bool isPressed(MouseButton button); 
    };
}


#endif  // MOUSE_H