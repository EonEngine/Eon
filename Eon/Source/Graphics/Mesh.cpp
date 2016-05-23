#include "Eon.h"
#include "Graphics/Mesh.h"

namespace eon {
namespace graphics {
int Mesh::AddTriangle(Triangle triangle) {
  triangles.push_back(triangle);
  GenerateVertexArray();
  return triangles.size() - 1;
}

void Mesh::RemoveTriangle(int index) {
  triangles.erase(triangles.begin() + index);
  GenerateVertexArray();
}

void Mesh::GenerateVertexArray() {
  int numVerts = triangles.size() * 9;
  std::vector<GLfloat> verts;
  GetGL(&verts);

  glDeleteVertexArrays(1, &id);

  glGenVertexArrays(1, &id);
  glBindVertexArray(id);

  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 24 * triangles.size(),
               &verts[0], GL_STATIC_DRAW);

  // Position data
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),
                        (GLvoid *)0);
  glEnableVertexAttribArray(0);
  // Color
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),
                        (GLvoid *)(3 * sizeof(GLfloat)));
  glEnableVertexAttribArray(1);
  // UVs
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),
                        (GLvoid *)(6 * sizeof(GLfloat)));
  glEnableVertexAttribArray(2);

  glBindVertexArray(0);
}

void Mesh::Render() {
  if (triangles.size() > 0) {
    glBindVertexArray(id);
    glDrawArrays(GL_TRIANGLES, 0, triangles.size() * 3);
    glBindVertexArray(0);
  }
}

void Mesh::GetGL(std::vector<GLfloat> *array) {
  for (int i = 0; i < triangles.size(); i++) {
    array->push_back((GLfloat)triangles[i].GetPoint1().GetX());
    array->push_back((GLfloat)triangles[i].GetPoint1().GetY());
    array->push_back((GLfloat)triangles[i].GetPoint1().GetZ());
    array->push_back((GLfloat)1.0);
    array->push_back((GLfloat)0.0);
    array->push_back((GLfloat)0.0);
    array->push_back((GLfloat)1.0);
    array->push_back((GLfloat)1.0);
    array->push_back((GLfloat)triangles[i].GetPoint2().GetX());
    array->push_back((GLfloat)triangles[i].GetPoint2().GetY());
    array->push_back((GLfloat)triangles[i].GetPoint2().GetZ());
    array->push_back((GLfloat)1.0);
    array->push_back((GLfloat)0.0);
    array->push_back((GLfloat)0.0);
    array->push_back((GLfloat)1.0);
    array->push_back((GLfloat)0.0);
    array->push_back((GLfloat)triangles[i].GetPoint3().GetX());
    array->push_back((GLfloat)triangles[i].GetPoint3().GetY());
    array->push_back((GLfloat)triangles[i].GetPoint3().GetZ());
    array->push_back((GLfloat)1.0);
    array->push_back((GLfloat)0.0);
    array->push_back((GLfloat)0.0);
    array->push_back((GLfloat)0.0);
    array->push_back((GLfloat)1.0);
  }
}
}
}
