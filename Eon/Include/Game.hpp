#ifndef EON_GAME_H
#define EON_GAME_H

#include "Renderer/Renderer.hpp"

class Game {
public:
    Game(Renderer* gameRenderer);

    void Start();
private:
    Renderer* renderer;
};

#endif