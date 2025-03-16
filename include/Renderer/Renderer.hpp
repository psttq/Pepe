#pragma once
#include <unordered_map>
#include <Renderer/Interface/IShader.hpp>
#include <Core/Types.hpp>
#include <optional>

#include <spdlog/spdlog.h>

namespace PEPE{

    class Renderer{
        
        Renderer(const Renderer &) = delete;
        Renderer &operator=(const Renderer &) = delete;
        
        
        std::unordered_map<std::string, sptr<IShader>> shaders_;
        
        protected:
        Renderer() = default;
        ~Renderer() = default;
        
        static Renderer *instance_;
        public:

        static Renderer &instance(){
            return *instance_;
        }

        
        static sptr<IShader> createShader(const std::string &name, const char *vertexPath, const char *fragmentPath);
        static std::optional<sptr<IShader>> getShader(const std::string &name);

        private:

        virtual sptr<IShader> createShader_(const char *vertexPath, const char *fragmentPath) = 0;

    };
}