#pragma once
#include <functional>
#include <unordered_map>

#include <spdlog/spdlog.h>

namespace PEPE
{
    class Window
    {
        public:
        using FramebufferSizeCallback = std::function<void(int, int)>;

        protected:
        static Window *window_;

        FramebufferSizeCallback framebufferSizeCallback_;
        
        virtual bool shouldClose_() = 0;
        virtual void swap_() = 0;
        virtual void pollEvents_() = 0;
        virtual void *getNativeWindow_() = 0;

        Window() = default;
        ~Window() = default;

        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        void init_(Window *handler)
        {
            window_ = handler;
        }

        void framebufferSizeHandler_(int width, int height){
            framebufferSizeCallback_(width, height);
        }

    public:
        static Window &instance()
        {
            return *window_;
        }

        static bool shouldClose()
        {
            return window_->shouldClose_();
        }

        static void swap()
        {
            window_->swap_();
        }

        static void pollEvents()
        {
            window_->pollEvents_();
        }

        static void *getNativeWindow()
        {
            return window_->getNativeWindow_();
        }

        static void setFramebufferSizeCallback(FramebufferSizeCallback framebufferSizeCallback){
            window_->framebufferSizeCallback_ = framebufferSizeCallback;
        }
    };
} // namespace PEPE