#ifndef EON_RENDERER_MESH_H
#define EON_RENDERER_MESH_H

#include <vector>

#include "Math/Vec3.hpp"

// TODO: Cache Floats() returns

class Mesh {
public:
    int AddVertex(Vec3 pos);
    void RemoveVertex(int index);

    void GetGL(GLfloat array[], int size);
private:
    std::vector<Vec3> vertices;
};

#endif
