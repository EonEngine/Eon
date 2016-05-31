#include "Common.h"

#include "Graphics/Material.h"

namespace eon {
namespace graphics {
Material::Material(Shader materialShader) : shader(materialShader) {}

void Material::Bind() {
  glUseProgram(shader.GetID());
  for (int i = 0; i < textures.size(); i++) {
    glActiveTexture(GL_TEXTURE0 + i);
    glBindTexture(GL_TEXTURE_2D, textures[i].GetID());
    glUniform1i(textureLocs[i], i);
  }
}

void Material::Unbind() { glUseProgram(0); }

void Material::AddTexture(Texture texture, const char *name) {
  textures.push_back(texture);
  textureLocs.push_back(glGetUniformLocation(shader.GetID(), name));
}
}
}
