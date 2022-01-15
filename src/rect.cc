#include "rect.h"
#include <SDL2/SDL.h>

Rect::Rect(float x, float y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Rect::operator SDL_Rect() const
{
    return SDL_Rect{(int)x, (int)y, w, h};
}
