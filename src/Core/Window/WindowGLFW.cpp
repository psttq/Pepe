#include <Core/Window/WindowGLFW.hpp>

namespace PEPE{
    WindowGLFW::WindowGLFW(const std::string &title, uint width, uint height) : Window(){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

        native_window_ =
        glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (native_window_ == NULL) {
            spdlog::error("WindowGLFW::WindowGLFW: Can't create window!");
            glfwTerminate();
            throw;
        }
        glfwMakeContextCurrent(native_window_);
    }

    WindowGLFW::~WindowGLFW(){
        glfwTerminate();
    }

    bool WindowGLFW::should_close_(){
        return glfwWindowShouldClose(native_window_);
    }

    void WindowGLFW::init(const std::string &title, uint width, uint height){
        window_ = new WindowGLFW(title, width, height);
    }

    void WindowGLFW::swap_(){
        glfwSwapBuffers(native_window_);
    }

    void WindowGLFW::poll_events_(){
        glfwPollEvents();
    }

    void *WindowGLFW::get_native_window_(){
        return static_cast<void *>(native_window_);
    }
}