#pragma once

#include <Core/Window.hpp>
#include <Core/Types.hpp>
#include <GLFW/glfw3.h>

namespace PEPE{
    class WindowGLFW : public Window
    {
        GLFWwindow *native_window_;     

        WindowGLFW(const std::string &title, uint width, uint height);
        ~WindowGLFW();

        bool shouldClose_() override;
        void swap_();
        void pollEvents_();
        void *getNativeWindow_() override;

        static WindowGLFW &instance_(){
            return *static_cast<WindowGLFW*>(&instance());
        }
        
        static void framebufferSizeCallback__(GLFWwindow *window, int width, int height);
        public:
        static void init(const std::string &title, uint width, uint height);
    };
}