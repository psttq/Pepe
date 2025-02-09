#pragma once

#include "Renderer/Interface/IVertexBuffer.hpp"
#include <Core/Types.hpp>
#include <Renderer/BufferLayout.hpp>

namespace PEPE {
class VertexBufferOpenGL : public IVertexBuffer {
    uint _count = 0;

  public:
    VertexBufferOpenGL(uptr<BufferLayout> layout);
    ~VertexBufferOpenGL() {
        if (id_ > 0) {
          glDeleteBuffers(1, &id_);
          spdlog::info("Deallocated VBO. Index: {}.", id_);
        };
    }

    void bind();
    void unbind();

    unsigned int getIndex() const;

    BufferLayout &getLayout() const;

    void setData(float *data, unsigned int size);

    uint count() const { return _count; }
};
} // namespace PEPE
