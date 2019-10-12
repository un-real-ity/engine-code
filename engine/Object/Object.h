#pragma once
#include <vector>
#include "Math/Transform.h"

class Object
{
public:
    Object();
    virtual ~Object();

    virtual void OnCreate() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void OnDestroy() = 0;

    void AddChild(Object* obj);
    void RemoveChild(Object* obj);

private:
    Object* parent;
    std::vector<Object*> children;
};
