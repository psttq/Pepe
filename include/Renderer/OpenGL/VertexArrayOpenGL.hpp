#pragma once

#include <Renderer/Interface/IVertexArray.hpp>

namespace PEPE
{

    class VertexArrayOpenGL : public IVertexArray
    {
    public:
        VertexArrayOpenGL();

        ~VertexArrayOpenGL()
        {
            if (_id > 0)
            {
                glDeleteVertexArrays(1, &_id);
            }
        }
        void bind() const;

        void unbind() const;
    };
} // namespace PEPE