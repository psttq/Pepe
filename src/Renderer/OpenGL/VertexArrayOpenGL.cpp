#include <Renderer/OpenGL/VertexArrayOpenGL.hpp>

namespace PEPE
{
    VertexArrayOpenGL::VertexArrayOpenGL()
    {
        glGenVertexArrays(1, &_id);
    }

    void VertexArrayOpenGL::bind() const
    {
        glBindVertexArray(_id);
    }

    void VertexArrayOpenGL::unbind() const
    {
        glBindVertexArray(0);
    }
}