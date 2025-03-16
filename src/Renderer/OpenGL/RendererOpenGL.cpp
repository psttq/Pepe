#include <Renderer/OpenGL/RendererOpenGL.hpp>
#include <Renderer/OpenGL/ShaderOpenGL.hpp>

namespace PEPE{
    RendererOpenGL::RendererOpenGL() : Renderer(){

    }

    sptr<IShader> RendererOpenGL::createShader_(const char *vertexPath, const char *fragmentPath){
        return ShaderOpenGL::create(vertexPath, fragmentPath);
    }
}