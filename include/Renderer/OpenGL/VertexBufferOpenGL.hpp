#pragma once

#include "Renderer/Interface/IVertexBuffer.hpp"
#include <Core/Types.hpp>
#include <Renderer/BufferLayout.hpp>

namespace PEPE {
class VertexBufferOpenGL : public IVertexBuffer {
    uint count_ = 0;

  public:
    VertexBufferOpenGL(uptr<BufferLayout> layout);
    ~VertexBufferOpenGL() {
        if (id_ > 0) {
          glDeleteBuffers(1, &id_);
        };
    }

    void bind() override;
    void unbind() override;

    void setData(float *data, unsigned int size) override;

    uint getElementsCount() const override { return count_; }
};
} // namespace PEPE
