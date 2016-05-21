#include <iostream>

#include "Eon.hpp"
#include "Renderer/Renderer.hpp"
#include "Entity/Entity.hpp"
#include "Entity/Component.hpp"

int main() {
    std::cout << "Eon v" << EON_VERSION << " Sandbox\n";

    Game game;
    Renderer renderer("Eon Sandbox", 640, 380);

    Entity entity;
    Component* component;
    entity.AddComponent(component);
    entity.RemoveComponent(component);

    game.Start();

    return 0;
}