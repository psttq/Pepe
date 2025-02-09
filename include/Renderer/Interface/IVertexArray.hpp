#pragma once

#include <Renderer/Interface/IVertexBuffer.hpp>
#include <Renderer/Interface/IIndexBuffer.hpp>
#include <spdlog/spdlog.h>
#include <vector>

namespace PEPE
{
    class IVertexArray
    {
    protected:
        unsigned int _id;
        std::vector<uptr<IVertexBuffer>> _vbos;
        uptr<IIndexBuffer> _indexBuffer = nullptr;

        unsigned int _index = 0;

    public:
        virtual void bind() const = 0;

        virtual void unbind() const = 0;

        void setIndexBuffer(uptr<IIndexBuffer> indexBuffer);

        void setVertexData(uint vboIndex, float *data, uint size);

        void addVertexBuffer(uptr<IVertexBuffer> vbo);

        bool isIndexBuffer() const;

        unsigned int indexCount();

        uint verticesCount();

        unsigned int getIndex() const
        {
            return _id;
        }
    };
} // namespace ENDER