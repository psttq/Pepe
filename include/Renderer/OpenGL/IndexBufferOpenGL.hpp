#pragma once

#include <spdlog/spdlog.h>
#include <Renderer/Interface/IIndexBuffer.hpp>

namespace PEPE
{

  class IndexBufferOpenGL : public IIndexBuffer
  {
    unsigned int count_;

  public:
    IndexBufferOpenGL(unsigned int *indices, unsigned int count);
    ~IndexBufferOpenGL();

    void bind() override;
    void unbind() override;

    uint getElementsCount() const override;
  };
}; // namespace PEPE