#include <SDL.h>

#include "Eon.hpp"
#include "Game.hpp"

void Game::Start()
{
    SDL_Event event;
    while(SDL_WaitEvent(&event) >= 0)
    {
        switch(event.type) 
        {
            case SDL_QUIT:
            {
                return;
            }
        }
    }
}