#pragma once
#include <functional>
#include <unordered_map>

#include <spdlog/spdlog.h>

namespace PEPE
{
    class Window
    {
        protected:
        static Window *window_;

        virtual bool should_close_() = 0;
        virtual void swap_() = 0;
        virtual void poll_events_() = 0;
        virtual void *get_native_window_() = 0;


        Window() = default;
        ~Window() = default;

        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        void init_(Window *handler){
            window_ = handler;
        }

        public:

        static Window &instance(){
            return *window_;
        }

        static bool should_close(){
            return window_->should_close_();
        }

        static void swap(){
            window_->swap_();
        }

        static void poll_events(){
            window_->poll_events_();
        }

        static void *get_native_window(){
            return window_->get_native_window_();
        }

    };
} // namespace PEPE