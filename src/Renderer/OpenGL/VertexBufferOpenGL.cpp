#include "Renderer/Interface/IVertexBuffer.hpp"
#include <Renderer/OpenGL/VertexBufferOpenGL.hpp>

namespace PEPE{
VertexBufferOpenGL::VertexBufferOpenGL(uptr<BufferLayout> layout)
    : IVertexBuffer()
{
  layout_ = std::move(layout);
  glGenBuffers(1, &id_);
}

void VertexBufferOpenGL::setData(float *data, unsigned int size)
{
  count_ = size / layout_->getStride();
  bind();
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
  // unbind();
}

void VertexBufferOpenGL::bind()
{
  glBindBuffer(GL_ARRAY_BUFFER, id_);

}

void VertexBufferOpenGL::unbind()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
}
