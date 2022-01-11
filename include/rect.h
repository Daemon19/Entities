#pragma once

#include <SDL.h>

class Rect
{
public:
    float x, y;
    int w, h;

    Rect(float x, float y, int w, int h);
    Rect() { *this = Rect(0, 0, 0, 0); }

    float bottom() const { return y + h; }
    void set_bottom(float val) { y = val - h; }

    operator SDL_Rect() const;
};