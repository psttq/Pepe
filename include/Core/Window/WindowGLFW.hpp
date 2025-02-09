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

        bool should_close_() override;
        void swap_();
        void poll_events_();
        void *get_native_window_() override;

        public:
        static void init(const std::string &title, uint width, uint height);
        
    };
}