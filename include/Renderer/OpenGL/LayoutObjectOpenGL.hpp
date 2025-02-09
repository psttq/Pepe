#pragma once

#include <Renderer/Interface/ILayoutObject.hpp>

namespace PEPE{
    struct LayoutObjectOpenGL : public ILayoutObject{
        LayoutObjectOpenGL(const LayoutObjectType &obj_type);

        void apply(uint attrib_index) override;
    };
}