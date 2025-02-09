#include <Renderer/OpenGL/IndexBufferOpenGL.hpp>
#include <glad/glad.h>

namespace PEPE{
IndexBufferOpenGL::IndexBufferOpenGL(unsigned int *indices, unsigned int count)
{
  count_ = count;
  glGenBuffers(1, &id_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices,
               GL_STATIC_DRAW);
  unbind();
}

IndexBufferOpenGL::~IndexBufferOpenGL()
{
  glDeleteBuffers(1, &id_);
}

void IndexBufferOpenGL::bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_); }

void IndexBufferOpenGL::unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

uint IndexBufferOpenGL::getElementsCount() const {
    return count_;
}
}