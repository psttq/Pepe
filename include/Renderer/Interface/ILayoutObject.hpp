#pragma once
#include <Core/Types.hpp>

namespace PEPE{
enum class LayoutObjectType
  {
    Float1,
    Float2,
    Float3,
    Float4
  };

  struct ILayoutObject
  {
    LayoutObjectType type;
    uint size = 0;
    uint stride = 0;
    size_t offset = 0;

    ILayoutObject(const LayoutObjectType &obj_type) { type = obj_type; }

    virtual void apply(uint attrib_index) = 0;
  };
}