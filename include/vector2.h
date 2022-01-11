#pragma once

class Vector2
{
public:
    float x, y;

    Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    Vector2() { Vector2(0, 0); }
};
