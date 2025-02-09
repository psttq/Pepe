#include <Renderer/Interface/IVertexArray.hpp>

namespace PEPE{
void IVertexArray::addVertexBuffer(uptr<IVertexBuffer> vbo) {
  bind();
  vbo->bind();
  spdlog::info("Adding VBO[Index: {}] to VAO[Index: {}]", vbo->getIndex(), _id);
  for (auto &el : vbo->getLayout()) {
    spdlog::debug("Applying vertex attribue with type {}",
                  BufferLayout::convertTypeToString(el->type));
    el->apply(_index);
    _index++;
  }
  _vbos.push_back(std::move(vbo));
}

bool IVertexArray::isIndexBuffer() const {
  return _indexBuffer != nullptr;
}

uint IVertexArray::verticesCount() {
  uint res = 0;
  for (auto &vbo : _vbos) {
    res += vbo->getElementsCount();
  }
  return res;
}

unsigned int IVertexArray::indexCount() {
  if (!isIndexBuffer()) {
    spdlog::error("Trying to get index buffer elements count but there is no "
                  "index buffer in the vertex array[id: {}]",
                  _id);
    return 0;
  }
  return _indexBuffer->getElementsCount();
}

void IVertexArray::setVertexData(uint vboIndex, float *data, uint size) {
  if (vboIndex < _vbos.size())
    _vbos.at(vboIndex).get()->setData(data, size);
}

void IVertexArray::setIndexBuffer(uptr<IIndexBuffer> indexBuffer) {
  bind();
  indexBuffer->bind();
  _indexBuffer = std::move(indexBuffer);
  unbind();
  spdlog::info("Adding IndexBuffer[Index: {}] to VAO[Index: {}]",
               _indexBuffer->getIndex(), _id);
}
}