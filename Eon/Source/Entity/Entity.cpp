#include "Eon.hpp"
#include "Entity/Entity.hpp"

void Entity::AddComponent(Component* component)
{
    components.push_back(component);
}

void Entity::RemoveComponent(Component* component)
{
    for(int i; i < components.size(); i++)
    {
        if (components[i] == component)
        {
            components.erase(components.begin() + i);
            break;
        }
    }
}

int Entity::NumComponents()
{
    return components.size();
}