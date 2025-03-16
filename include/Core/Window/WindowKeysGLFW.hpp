#pragma once
#include <Core/Window/WindowKeys.hpp>
#include <GLFW/glfw3.h>

namespace PEPE
{
    struct WindowKeysGLFW : public WindowKeys
    {
        WindowKeysGLFW() : WindowKeys(){
            ESCAPE = GLFW_KEY_ESCAPE;
            A = GLFW_KEY_A;
        }
    };
}