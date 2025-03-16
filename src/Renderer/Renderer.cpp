#include <Renderer/Renderer.hpp>

namespace PEPE{
    Renderer *Renderer::instance_ = nullptr;

     sptr<IShader> Renderer::createShader(const std::string &name, const char *vertexPath, const char *fragmentPath){
        auto shaderIter = instance().shaders_.find(name);
        if(shaderIter != instance().shaders_.end())
        {
            spdlog::error("Renderer::createShader: Shader with name '{}' already exits!", name);
            throw;
        }
            auto shader = instance().createShader_(vertexPath, fragmentPath);
            instance().shaders_.insert({name, shader});
            return shader;
       }
     std::optional<sptr<IShader>> Renderer::getShader(const std::string &name){
        auto shaderIter = instance().shaders_.find(name);
        return (shaderIter != instance().shaders_.end() ? std::optional((*shaderIter).second) : std::nullopt);
     }
}