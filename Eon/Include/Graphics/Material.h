#ifndef EON_GRAPHICS_MATERIAL_H
#define EON_GRAPHICS_MATERIAL_H

#include "Graphics/Shader.h"
#include "Graphics/Texture.h"

namespace eon {
namespace graphics {
class Material {
public:
  Material(Shader materialShader);

  inline GLuint GetModel() { return shader.GetModel(); };
  inline GLuint GetView() { return shader.GetView(); };
  inline GLuint GetProj() { return shader.GetProj(); };

  void Bind();
  void Unbind();

  inline void PrintNumTextures() { std::cout << textures.size(); };

  void AddTexture(Texture texture, const char *name);

private:
  Shader shader;
  std::vector<Texture> textures;
  std::vector<GLuint> textureLocs;
};
}
}

#endif
