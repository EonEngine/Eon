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
  GetGL(&verts, numVerts);

  glDeleteVertexArrays(1, &id);

  glGenVertexArrays(1, &id);
  glBindVertexArray(id);

  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * numVerts, &verts[0],
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                        (GLvoid *)0);
  glEnableVertexAttribArray(0);

  glDrawArrays(GL_TRIANGLES, 0, 6);
  glBindVertexArray(0);

  glBindVertexArray(0);
}

void Mesh::Render() {
  if (triangles.size() > 0) {
    glBindVertexArray(id);
    glDrawArrays(GL_TRIANGLES, 0, triangles.size() * 3);
    glBindVertexArray(0);
  }
}

void Mesh::GetGL(std::vector<GLfloat> *array, int size) {
  for (int i = 0; i < triangles.size(); i++) {
    array->push_back((GLfloat)triangles[i].GetPoint1().GetX());
    array->push_back((GLfloat)triangles[i].GetPoint1().GetY());
    array->push_back((GLfloat)triangles[i].GetPoint1().GetZ());
    array->push_back((GLfloat)triangles[i].GetPoint2().GetX());
    array->push_back((GLfloat)triangles[i].GetPoint2().GetY());
    array->push_back((GLfloat)triangles[i].GetPoint2().GetZ());
    array->push_back((GLfloat)triangles[i].GetPoint3().GetX());
    array->push_back((GLfloat)triangles[i].GetPoint3().GetY());
    array->push_back((GLfloat)triangles[i].GetPoint3().GetZ());
  }
}
}
}
