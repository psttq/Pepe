#include <Renderer/OpenGL/LayoutObjectOpenGL.hpp>
#include <Renderer/BufferLayout.hpp>
#include <glad/glad.h>

namespace PEPE{
    LayoutObjectOpenGL::LayoutObjectOpenGL(const LayoutObjectType &obj_type) : ILayoutObject(obj_type){

    }
    void LayoutObjectOpenGL::apply(uint attrib_index){
        glVertexAttribPointer(attrib_index,
                            BufferLayout::convertTypeToNumberOfElements(type),
                            BufferLayout::convertTypeToGLType(type), GL_FALSE,
                            stride, (const void *)offset);
        glEnableVertexAttribArray(attrib_index);
    }
}