#ifndef EON_ENTITY_ENTITY_H
#define EON_ENTITY_ENTITY_H

#include <vector>

#include "Component.hpp"

// TODO: Use hash map for components

class Entity {
public:    
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
    int NumComponents();
private:
    std::vector<Component*> components;
};

#endif
