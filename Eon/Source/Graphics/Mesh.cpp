#include <vector>
#include "Common.h"

#include "Graphics/Mesh.h"

namespace eon {
namespace graphics {
Mesh::Mesh(float *verts, int numVertices, bool texCoords) {
  if (texCoords) {
    for (int i = 0; i < numVertices * 5; i += 5) {
      vertices.push_back(Vertex(Vec3(verts[i], verts[i + 1], verts[i + 2]),
                                Vec2(verts[i + 3], verts[i + 4])));
    }
  } else {
    for (int i = 0; i < numVertices * 3; i += 3) {
      vertices.push_back(Vertex(Vec3(verts[i], verts[i + 1], verts[i + 2])));
    }
  }
  GenerateVertexArray();
}

int Mesh::AddVertex(Vertex vertex) {
  vertices.push_back(vertex);
  GenerateVertexArray();
  return vertices.size() - 1;
}

void Mesh::RemoveVertex(int index) {
  vertices.erase(vertices.begin() + index);
  GenerateVertexArray();
}

void Mesh::GenerateVertexArray() {
  std::vector<GLfloat> verts;
  GetGL(&verts);

  glDeleteVertexArrays(1, &id);

  glGenVertexArrays(1, &id);
  glBindVertexArray(id);

  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 5 * vertices.size(),
               &verts[0], GL_STATIC_DRAW);

  // Position data
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                        (GLvoid *)0);
  glEnableVertexAttribArray(0);
  // UVs
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat),
                        (GLvoid *)(3 * sizeof(GLfloat)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);
}

void Mesh::Render() {
  if (vertices.size() > 0) {
    glBindVertexArray(id);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    glBindVertexArray(0);
  }
}

void Mesh::GetGL(std::vector<GLfloat> *array) {
  for (int i = 0; i < vertices.size(); i++) {
    array->push_back((GLfloat)vertices[i].pos.x);
    array->push_back((GLfloat)vertices[i].pos.y);
    array->push_back((GLfloat)vertices[i].pos.z);
    array->push_back((GLfloat)vertices[i].tex.x);
    array->push_back((GLfloat)vertices[i].tex.y);
  }
}
}
}
