#pragma once
#include "Renderer/Interface/IShader.hpp"
#include <Core/Types.hpp>
#include <string>

namespace PEPE {
class ShaderOpenGL : public IShader {
    unsigned int id_;

    ShaderOpenGL(const char *vertexPath, const char *fragmentPath);
  public:
  
    static sptr<ShaderOpenGL> create(const char *vertexPath, const char *fragmentPath);

    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

  private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
} // namespace PEPE
