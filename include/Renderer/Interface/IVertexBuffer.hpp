#pragma once

#include <Renderer/BufferLayout.hpp>
#include <Core/Types.hpp>

namespace PEPE
{
  class IVertexBuffer
  {
    protected:
    unsigned int id_ = 0;
    uptr<BufferLayout> layout_;

  public:
    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void setData(float *data, unsigned int size) = 0;

    virtual unsigned int getIndex() const{
      return id_;
    }

    BufferLayout &getLayout() const{
      return *layout_;
    }
  };
} // namespace ENDER
