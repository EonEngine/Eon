#include <SDL.h>

#include "Eon.hpp"
#include "Renderer/Renderer.hpp"

Renderer::Renderer(const char* name, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL Error: " << SDL_GetError() << "\n";
        //return NULL;
    }
    
    SDL_Window* window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    if (window == NULL) {
        std::cout << "SDL Window Error: " << SDL_GetError() << "\n";
        //return NULL;
    }
    
    //SDL_DestroyWindow(window);
}

Renderer::~Renderer()
{
    //InitSDL(name, width, height);
}