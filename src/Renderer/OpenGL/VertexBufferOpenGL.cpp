#include "Renderer/Interface/IVertexBuffer.hpp"
#include <Renderer/OpenGL/VertexBufferOpenGL.hpp>

namespace PEPE{
VertexBufferOpenGL::VertexBufferOpenGL(uptr<BufferLayout> layout)
    : IVertexBuffer()
{
  layout_ = std::move(layout);
  glGenBuffers(1, &id_);

  spdlog::info("Created VBO. Index: {}", id_);

}

void VertexBufferOpenGL::setData(float *data, unsigned int size)
{
  _count = size / layout_->getStride();

  spdlog::debug("Setting data to VBO. Index: {}. Size of data: {} -> Count of elements: {}", id_, size, _count);

  bind();

  glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
  // unbind();
}

void VertexBufferOpenGL::bind()
{
  spdlog::debug("Bind VBO. Index: {}", id_);

  glBindBuffer(GL_ARRAY_BUFFER, id_);

}

void VertexBufferOpenGL::unbind()
{
  spdlog::debug("Unbind VBO. Index: {}", id_);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
}
