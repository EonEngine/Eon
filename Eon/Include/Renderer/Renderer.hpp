#ifndef EON_RENDERER_RENDERER_H
#define EON_RENDERER_RENDERER_H

#include <SDL.h>

class Renderer {
public:
    Renderer(const char* name, int width, int height);
    ~Renderer();
private:
    SDL_Window* window;
};


#endif
