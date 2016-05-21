#include "Eon.hpp"
#include "Renderer/Mesh.hpp"

int Mesh::AddVertex(Vec3 pos)
{
  vertices.push_back(pos);
}

void Mesh::RemoveVertex(int index)
{
  vertices.erase(vertices.begin() + index);
}

void Mesh::GetGL(GLfloat array[], int size)
{
  int i = 0;
  int v = 0;
  for(i; i < size; i += 3)
  {
    array[i] = vertices[v].GetX();
    array[i + 1] = vertices[v].GetY();
    array[i + 2] = vertices[v].GetZ();
    v++;
  }
}
