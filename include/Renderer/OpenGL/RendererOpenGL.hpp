#pragma once
#include <Renderer/Renderer.hpp>

namespace PEPE
{
    class RendererOpenGL : public Renderer
    {
    private:
        RendererOpenGL();

        sptr<IShader> createShader_(const char *fragmentPath, const char *vertexPath) override;

    public:
        static void init()
        {
            instance_ = new RendererOpenGL();
        }
    };
}