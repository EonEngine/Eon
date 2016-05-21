#ifndef EON_RENDERER_RENDERER_H
#define EON_RENDERER_RENDERER_H

#include <vector>
#include <SDL.h>

#include "Renderer/Color.hpp"
#include "Renderer/Mesh.hpp"

class Renderer {
public:
    Renderer(const char* name, int width, int height);
    ~Renderer();

    void Render();

    void AddMesh(Mesh* mesh);
    void RemoveMesh(Mesh* mesh);

    void SetBackgroundColor(Color color);
    Color GetBackgroundColor();
private:
    SDL_Window* window;
    Color bgColor;

    std::vector<Mesh*> meshes;

    std::vector<GLuint> vaos;
};


#endif
