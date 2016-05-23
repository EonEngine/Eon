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
  if (triangles.size() > 0) {
    glBindVertexArray(id);
    glDrawArrays(GL_TRIANGLES, 0, triangles.size() * 3);
    glBindVertexArray(0);
  }
}

void Mesh::GetGL(std::vector<GLfloat> *array) {
  for (int i = 0; i < triangles.size(); i++) {
    array->push_back((GLfloat)triangles[i].p1.x);
    array->push_back((GLfloat)triangles[i].p1.y);
    array->push_back((GLfloat)triangles[i].p1.z);
    array->push_back((GLfloat)triangles[i].p1Tex.x);
    array->push_back((GLfloat)triangles[i].p1Tex.y);
    array->push_back((GLfloat)triangles[i].p2.x);
    array->push_back((GLfloat)triangles[i].p2.y);
    array->push_back((GLfloat)triangles[i].p2.z);
    array->push_back((GLfloat)triangles[i].p2Tex.x);
    array->push_back((GLfloat)triangles[i].p2Tex.y);
    array->push_back((GLfloat)triangles[i].p3.x);
    array->push_back((GLfloat)triangles[i].p3.y);
    array->push_back((GLfloat)triangles[i].p3.z);
    array->push_back((GLfloat)triangles[i].p3Tex.x);
    array->push_back((GLfloat)triangles[i].p3Tex.y);
  }
}
}
}
