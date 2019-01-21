#include <iostream>

#include "keyboard.h"

namespace sap::io
{

    void Keyboard::init()
    {
        for(int i = 0; i < int(Key::NUM_KEYS); ++i)
            Keyboard::m_keys[i] = false;
    }

    KeyState Keyboard::getKeyState(Key key)
    {
        KeyState keyState = {key};

        return keyState;
    }

    bool Keyboard::isPressed(Key key)
    {
        std::cout << "isPressed function called" << std::endl;
        return Keyboard::m_keys[static_cast<int>(key)];
    }


    bool Keyboard::isReleased(Key key)
    {
        return !isPressed(key);
    }


    bool Keyboard::isRepeated(Key key)
    {
        return true;
    }
}