#pragma once

#include <spdlog/spdlog.h>
#include <Core/Types.hpp>

namespace PEPE
{
  class IIndexBuffer
  {
  protected:
    unsigned int id_;

  public:
    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual uint getElementsCount() const  = 0;

    unsigned int getIndex()
    {
      return id_;
    }
    
  };
}; // namespace PEPE