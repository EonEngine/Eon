#include <iostream>
#include <vector>

#include <Eon.hpp>
#include <Entity/Entity.hpp>
#include <Entity/Component.hpp>
#include <Math/Vec3.hpp>
#include <Renderer/Color.hpp>
#include <Renderer/Renderer.hpp>
#include <Renderer/Mesh.hpp>

int main() {
    std::cout << "Eon v" << EON_VERSION << " Sandbox" << std::endl;

    Renderer renderer("Eon Sandbox", 1336, 768);
    Game game(&renderer);
    renderer.SetBackgroundColor(Color(0.1, 0.1, 0.1, 1));

    Mesh triangle;
    triangle.AddVertex(Vec3(-0.5, -0.5, 0));
    triangle.AddVertex(Vec3(0.5, -0.5, 0));
    triangle.AddVertex(Vec3(0, 0.5, 0));

    Mesh shape;
    shape.AddVertex(Vec3(-0.9, -0.9, 0));
    shape.AddVertex(Vec3(0.1, -0.9, 0));
    shape.AddVertex(Vec3(0, 0.1, 0));

    renderer.AddMesh(&shape);
    renderer.AddMesh(&triangle);

    Entity entity;
    Component* component;
    entity.AddComponent(component);
    entity.RemoveComponent(component);

    game.Start();

    return 0;
}
