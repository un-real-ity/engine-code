#pragma once
#include "Vector2D.h"

struct Transform
{
public:
    Transform()
        : position(0, 0), rotation(0), scale(1, 1) {}
    Transform(Vector2D position_, Vector2D scale_, float rotation_)
        : position(position_),scale(scale_), rotation(rotation_) {}

    Vector2D position;
    Vector2D scale;
    float rotation;

private:
};
